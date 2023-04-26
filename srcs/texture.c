/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:00:31 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/25 22:08:58 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//light direcrtion ob.ob_hit.p - light.point
t_vector	diffuse_mat(t_object ob, t_cam *c, t_vector dir)
{
	t_vector	l;
	(void)		dir;
	(void)ob;

	l = vector_sub(c->light.point, vector_normalize(ob.ob_hit.p));
	l = vector_normalize(l);
	return (l);
}

t_vector	specular_mat(t_object ob, t_cam *c, t_vector dir)
{
	t_vector	s;
	(void)		c;

	s = vector_add(dir, vector_normalize(ob.ob_hit.p));
	s = vector_normalize(s);
	return (s);
}

float	is_shadow(t_cam *c, t_vector cam, t_vector ldir, t_object *ob, int idx)
{
	int		i;
	int		t;
	int		id;
	(void)idx;
	(void)c;

	i = 0;
	id = -1;
	t = -1;
	// printf("idx : %d, %f, %f, %f\n", idx, ob[idx].ob_hit.p.x, ob[idx].ob_hit.p.y, ob[idx].ob_hit.p.z);
	while (ob[i].type)
	{
		t = hit_object(&ob[i], ldir, cam, c->t_max);
		if (t != -1)
		{
			c->t_max = ob[i].ob_hit.t;
			id = t;
		}
		i++;
	}
	c->t_max = T_MAX;
	if (id > -1)
	{
		// printf("hit : %d, %f, %f, %f\n", id, ob[id].ob_hit.p.x, ob[id].ob_hit.p.y, ob[id].ob_hit.p.z);
		return (id);
	}
	return (-1);
}

t_vector	reflect_light(t_vector n, t_vector l)
{
	t_vector	reflec;

	reflec = vector_sub(l, vector_mul(n, dot_product(n, l)));
	return (reflec);
}

t_vector	isreflect(t_vector v, t_vector n)
{
	t_vector	dot_n;

	dot_n = vector_mul(n, 2 * dot_product(v, n));
	return (vector_sub(v, dot_n));
}

int	near_zero(t_vector v)
{
	float	s;

	s = 0.001;
	return ((fabs(v.x) < s) && (fabs(v.y) < s) && (fabs(v.z) < s));
}

t_color	metal_reflec(t_cam *c, t_object *ob, t_object *ob_h, t_vector dir, int depth)
{
	t_ray		scattered;
	t_vector	reflec;
	t_vector	fuzz;

	reflec = isreflect(dir, ob_h->ob_hit.normal);
	scattered.origin = ob_h->ob_hit.p;
	scattered.t = ob_h->ob_hit.t;
	scattered.dir = reflec;
	if ((dot_product(reflec, ob_h->ob_hit.normal) > 0))
	{	
		if (!strcmp(ob_h->reflec, "fu"))
		{
			fuzz = vector_mul(rand_in_sphere(), rand_between(0.1, 1));
			scattered.dir = vector_add(scattered.dir, fuzz);
		}
		return (ray_color(c, scattered.origin, scattered.dir, ob, depth - 1));
	}
	return ((t_color){0, 0, 0});
}

//color_mul(color_add(ob[i].color, ray_color(ob[i].ob_hit.p, n_p, ob, depth - 1)), 0.5);
