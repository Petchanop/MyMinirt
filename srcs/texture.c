/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:00:31 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/06 16:37:08 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	diffuse_mat(t_object ob)
{
	t_vector	n_p;

	n_p = vector_add(ob.ob_hit.p, ob.ob_hit.normal);
	n_p = vector_add(n_p, vector_normalize(random_hemisphere(ob.ob_hit.normal)));
	n_p = vector_sub(n_p, ob.ob_hit.p);
	return (n_p);
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

	reflec = isreflect(vector_normalize(dir), ob_h->ob_hit.normal);
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
