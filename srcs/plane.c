/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:38:18 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/25 23:38:49 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	hit_disk(t_object *ob, t_vector v, t_vector cam, t_vector p, float t)
{
	t_vector	p0;
	t_vector	w;
	float		d;

	p0 = vector_add(vector_mul(v, t), cam);
	w = vector_sub(p, p0);
	d = vector_length(w);
	if (sqrt(d) <= ob->radius)
		return (ob->index);
	return (-1);
}

int	hit_plane(t_object *ob, t_vector v, t_vector cam, float t_max)
{
	float		t;
	float		denom;
	t_vector	p;

	denom = dot_product(ob->vector, v);
	t = 0.0;
	p = (t_vector){0, 0, 0, 0};
	if (fabs(denom) < 0.0001f)
		return (-1);
	p = vector_sub(ob->center, cam);
	t = dot_product(p, ob->vector) / denom;
	if (t < T_MIN || t_max < t)
		return (-1);
	ob->ob_hit.t = t;
	ob->ob_hit.p = vector_add(cam, vector_mul(v, ob->ob_hit.t));
	ob->ob_hit.normal = ob->vector;
	return (ob->index);
}
