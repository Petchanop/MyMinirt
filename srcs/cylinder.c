/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:59:05 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/04 02:08:39 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	hit_cap(t_object *ob, t_vector cam, t_vector v, float t_max)
{
	float		denom;
	float		t;
	t_vector	p;

	denom = dot_product(ob->vector, v);
	t = 0.0;
	p = (t_vector){0, 0, 0, 0};
	if (fabs(denom) < 0.0001f)
		return (-1);
	p = vector_sub(ob->t_cap, cam);
	t = dot_product(p, ob->vector) / denom;
	if (T_MIN < t && t < t_max)
	{
		printf("hit tcap\n");
		return (hit_disk(ob, v, cam, ob->t_cap, t));
	}
	p = vector_sub(ob->b_cap, cam);
	t = dot_product(p, ob->vector) / denom;
	if (T_MIN < t && t < t_max)
		return (hit_disk(ob, v, cam, ob->b_cap, t));
	return (-1);
}

int	hit_body(t_object *ob, t_vector v, t_vector cam, float t[], int inside)
{
	t_vector	point;
	t_vector	ori_diff;
	float		dtop;
	t_vector	point_cent;
	t_vector	pc;

	point = vector_add(cam, vector_mul(v, t[0]));
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

int	hit_cylinder(t_object *ob, t_vector v, t_vector cam, float t_max)
{
	float		sdis;
	float		t[2];
	t_vector	oc;

	oc = vector_sub(cam, ob->center);
	ob->ob_hit.a = pow(dot_product(v, v), 2) - pow(dot_product(v, ob->vector), 2);
	ob->ob_hit.b = (dot_product(v, oc) - dot_product(v, ob->vector) * dot_product(oc, ob->vector));
	ob->ob_hit.c = dot_product(oc, oc) - pow(dot_product(oc, ob->vector), 2) - pow(ob->radius, 2);
	ob->ob_hit.dis = (pow(ob->ob_hit.b, 2)) - (ob->ob_hit.a * ob->ob_hit.c);
	sdis = sqrt(ob->ob_hit.dis);
	if (ob->ob_hit.dis < 0)
		return (-1);
	t[0] = ((-ob->ob_hit.b - sdis) / ob->ob_hit.a);
	t[1] = t_max;
	if (t[0] > T_MIN && t[0] < t_max)
	{
		if (hit_body(ob, v, cam, t, 0) != -1)
			return (ob->index);
	}
	t[0] = (-ob->ob_hit.b + sdis) / ob->ob_hit.a;
	if (t[1] > T_MIN && t[1] < t_max)
	{
		if (hit_body(ob, v, cam, t, 0) != -1)
			return (ob->index);
	}
	return (hit_cap(ob, v, cam, t[1]));
}

// int	hit_cylinder(t_object *ob, t_vector v, t_vector cam, float t_max)
// {
// 	float	sdis;

// 	ob->ob_hit.a = pow(v.x, 2) - pow(v.z, 2);
// 	ob->ob_hit.b = (2 * cam.x * v.x) + (2 * cam.z * v.z);
// 	ob->ob_hit.c = pow(cam.x, 2) + pow(cam.z, 2) - 1;
// 	ob->ob_hit.dis = (pow(ob->ob_hit.b, 2)) - (4 * ob->ob_hit.a * ob->ob_hit.c);
// 	sdis = sqrt(ob->ob_hit.dis);
// 	if (ob->ob_hit.dis < 0)
// 		return (-1);
// 	return (hit_caps(ob, sdis, v, cam, t_max));
// }