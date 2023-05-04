/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:00:31 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 01:48:51 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	specular_mat(t_object ob, t_cam *c, t_vector dir)
{
	t_vector	s;
	(void)		c;

	s = vector_add(dir, vector_normalize(ob.ob_hit.p));
	s = vector_normalize(s);
	return (s);
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
		return (ray_color(c, scattered, ob, depth - 1));
	}
	return ((t_color){0, 0, 0});
}

//color_mul(color_add(ob[i].color, ray_color(ob[i].ob_hit.p, n_p, ob, depth - 1)), 0.5);
