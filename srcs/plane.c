/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:38:18 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/11 17:39:31 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	hit_disk(t_object *ob, t_ray r, t_vector p, float t)
{
	t_vector	p0;
	t_vector	w;
	float		d;

	p0 = vector_add(vector_mul(r.dir, t), r.origin);
	w = vector_sub(p, p0);
	d = dot_product(w, w);
	if (sqrt(d) <= ob->radius)
	{
		ob->ob_hit.t = t;
		ob->ob_hit.p = p0;
		ob->ob_hit.normal = ob->ob_hit.normal;
		if (ob->ob_hit.normal.z < 0)
			ob->ob_hit.normal.z *= -1;
		return (ob->index);
	}
	return (-1);
}

int	hit_plane(t_object *ob, t_ray r, float t_max)
{
	float		t;
	float		denom;
	t_vector	p;

	denom = dot_product(ob->vector, r.dir);
	t = 0.0;
	p = (t_vector){0, 0, 0, 0};
	if (fabs(denom) < 1e-6)
		return (-1);
	p = vector_sub(ob->center, r.origin);
	t = dot_product(p, ob->vector) / denom;
	if (t < T_MIN || t_max < t)
		return (-1);
	ob->ob_hit.t = t;
	ob->ob_hit.p = vector_add(r.origin, vector_mul(r.dir, ob->ob_hit.t));
	ob->ob_hit.normal = ob->vector;
	if (denom > 0)
		ob->ob_hit.normal = vector_mul(ob->vector, -1);
	return (ob->index);
}
