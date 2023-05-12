/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:46:46 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/11 17:12:34 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	hit_cone_cap(t_object *ob, t_ray r, float t_max)
{
	float		t;
	float		denom;
	t_vector	p;

	denom = dot_product(ob->vector, r.dir);
	t = 0.0;
	p = (t_vector){0, 0, 0, 0};
	if (denom < 0)
		return (-1);
	p = vector_sub(ob->b_cap, r.origin);
	t = dot_product(p, ob->vector) / denom;
	ob->ob_hit.normal = ob->vector;
	if (t < T_MIN || t_max < t)
		return (-1);
	ob->ob_hit.t = t;
	ob->ob_hit.p = vector_add(r.origin, vector_mul(r.dir, ob->ob_hit.t));
	if (hit_disk(ob, r, ob->b_cap, t) != -1)
	{
		if (denom > 0)
			ob->ob_hit.normal = vector_mul(ob->vector, -1);
		return (ob->index);
	}
	return (-1);
}

int	hit_cone_body(t_object *ob, t_ray r, float t[])
{
	t_vector	oc;
	t_vector	ori_diff;
	t_vector	point_cent;
	float		dtop;

	ob->ob_hit.p = vector_add(r.origin, vector_mul(r.dir, t[0]));
	ori_diff = vector_sub(ob->center, ob->ob_hit.p);
	dtop = dot_product(ori_diff, ob->vector);
	ob->ob_hit.t = t[0];
	point_cent = vector_add(ob->center, vector_mul(ob->vector, -dtop));
	oc = vector_sub(ob->ob_hit.p, point_cent);
	ob->ob_hit.normal = vector_normalize(oc);
	return (ob->index);
}

int	hit_cone(t_object *ob, t_ray r, float t_max)
{
	float		sdis;
	float		t[2];
	float		dot[3];
	float		m[2];
	t_vector	oc;

	oc = vector_sub(r.origin, ob->t_cap);
	dot[0] = dot_product(r.dir, r.dir);
	dot[1] = dot_product(r.dir, ob->vector);
	dot[2] = dot_product(oc, ob->vector);
	ob->ob_hit.a = pow(dot[0], 2) - pow(dot[1], 2) * ob->k;
	ob->ob_hit.b = (dot_product(r.dir, oc) - dot[1] * dot[2] * ob->k);
	ob->ob_hit.c = dot_product(oc, oc) - pow(dot[2], 2) * ob->k;
	ob->ob_hit.dis = (pow(ob->ob_hit.b, 2)) - (ob->ob_hit.a * ob->ob_hit.c);
	sdis = sqrt(ob->ob_hit.dis);
	if (ob->ob_hit.dis < 0)
		return (-1);
	t[0] = (-ob->ob_hit.b - sdis) / ob->ob_hit.a;
	m[0] = -1;
	if (!(t[0] < T_MIN || t_max < t[0]))
		m[0] = dot[1] * t[0] + dot_product(oc, ob->vector);
	if (m[0] != -1 && m[0] < 0 && fabs(m[0]) < ob->height)
		return (hit_cone_body(ob, r, t));
	t[1] = t_max;
	return (hit_cone_cap(ob, r, t[1]));
}
