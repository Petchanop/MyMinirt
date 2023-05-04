/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:59:05 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/04 16:39:06 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	hit_cap(t_object *ob, t_ray r, float t_max)
{
	float		denom;
	float		t[2];
	int			compare[2];
	t_vector	p[2];

	denom = dot_product(ob->vector, r.dir);
	compare[0] = -1;
	compare[1] = -1;
	if (fabs(denom) < 0.0001f)
		return (-1);
	p[0] = vector_sub(ob->t_cap, r.origin);
	t[0] = dot_product(p[0], ob->vector) / denom;
	p[1] = vector_sub(ob->b_cap, r.origin);
	t[1] = dot_product(p[1], ob->vector) / denom;
	ob->ob_hit.normal = ob->vector;
	if (denom > 0)
		ob->ob_hit.normal = vector_mul(ob->vector, -1);
	if (T_MIN < t[0] && t[0] < t_max)
		compare[0] = hit_disk(ob, r, ob->t_cap, t[0]);
	if (T_MIN < t[1] && t[1] < t_max)
		compare[1] = hit_disk(ob, r, ob->b_cap, t[1]);
	if (compare[0] != -1 && compare[1] != -1)
	{
		if (t[0] < t[1])
		{
			ob->ob_hit.t = t[0];
			ob->ob_hit.p = vector_add(vector_mul(r.dir, t[0]), r.origin);
		}
		else
		{
			ob->ob_hit.t = t[1];
			ob->ob_hit.p = vector_add(vector_mul(r.dir, t[1]), r.origin);
		}
		if (denom > 0)
			ob->ob_hit.normal = vector_mul(ob->vector, -1);
		return (ob->index);
	}
	else if (compare[0] != -1)
	{
		ob->ob_hit.t = t[0];
		ob->ob_hit.p = vector_add(vector_mul(r.dir, t[0]), r.origin);
		if (denom > 0)
			ob->ob_hit.normal = vector_mul(ob->vector, -1);
		return (ob->index);
	}
	else if (compare[1] != -1)
	{
		ob->ob_hit.t = t[1];
		ob->ob_hit.p = vector_add(vector_mul(r.dir, t[1]), r.origin);
		if (denom > 0)
			ob->ob_hit.normal = vector_mul(ob->vector, -1);
		return (ob->index);
	}
	return (-1);
}

int	hit_body(t_object *ob, t_ray r, float t[], int inside)
{
	t_vector	point;
	t_vector	ori_diff;
	float		dtop;
	t_vector	point_cent;
	t_vector	pc;

	point = vector_add(r.origin, vector_mul(r.dir, t[0]));
	ori_diff = vector_sub(ob->center, point);
	dtop = dot_product(ori_diff, ob->vector);
	if (fabs(dtop) > ob->height / 2)
		return (-1);
	point_cent = vector_add(ob->center, vector_mul(ob->vector, -dtop));
	ob->ob_hit.t = t[0];
	ob->ob_hit.p = point;
	pc = vector_sub(point, point_cent);
	ob->ob_hit.normal = vector_normalize(pc);
	if (inside)
		ob->ob_hit.normal = vector_mul(ob->ob_hit.normal, -1);
	return (ob->index);
}

int	hit_cylinder(t_object *ob, t_ray r, float t_max)
{
	float		sdis;
	float		t[2];
	t_vector	oc;

	oc = vector_sub(r.origin, ob->center);
	ob->ob_hit.a = pow(dot_product(r.dir, r.dir), 2) - pow(dot_product(r.dir, ob->vector), 2);
	ob->ob_hit.b = (dot_product(r.dir, oc) - dot_product(r.dir, ob->vector) * dot_product(oc, ob->vector));
	ob->ob_hit.c = dot_product(oc, oc) - pow(dot_product(oc, ob->vector), 2) - pow(ob->radius, 2);
	ob->ob_hit.dis = (pow(ob->ob_hit.b, 2)) - (ob->ob_hit.a * ob->ob_hit.c);
	sdis = sqrt(ob->ob_hit.dis);
	if (ob->ob_hit.dis < 0)
		return (-1);
	t[0] = ((-ob->ob_hit.b - sdis) / ob->ob_hit.a);
	t[1] = t_max;
	if (t[0] > T_MIN && t[0] < t_max)
	{
		if (hit_body(ob, r, t, 0) != -1)
			return (ob->index);
	}
	t[0] = (-ob->ob_hit.b + sdis) / ob->ob_hit.a;
	if (t[1] > T_MIN && t[1] < t_max)
	{
		if (hit_body(ob, r, t, 0) != -1)
			return (ob->index);
	}
	return (hit_cap(ob, r, t[1]));
}
