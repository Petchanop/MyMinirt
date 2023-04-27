/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:59:05 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/27 16:47:35 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	hit_caps(t_object *ob, float sdis, t_vector v, t_vector cam, float t_max)
{
	t_vector	p0;
	t_vector	oc;
	float		root;

	root = ((-ob->ob_hit.b - sdis) / ob->ob_hit.a);
	if (root < T_MIN || t_max < root)
	{
		root = (-ob->ob_hit.b + sdis) / ob->ob_hit.a;
		if (root < T_MIN || t_max < root)
			return (-1);
	}
	oc = vector_sub(cam, ob->b_cap);
	float m = dot_product(v, ob->vector) * root + dot_product(oc, ob->vector);
	if (m < T_MIN || t_max < m)
		return (-1);
	// oc = vector_sub(cam, ob->t_cap);
	// float m2 = dot_product(v, ob->vector) * root + dot_product(oc, ob->vector);
	// if (m)
	// 	return (-1);
	// float m = m2;
	p0 = vector_add(vector_mul(v, root), cam);
	// printf("hit cap : %f, %f, %f\n", p0.x, p0.y, p0.z);
	float denom = dot_product(ob->vector, v);
	if (fabs(denom) < 0.0001f)
		return (ob->index);
	t_vector p = vector_sub(p0, cam);
	// t_vector p1 = vector_sub(ob->b_cap, cam);
	// t_vector c = vector_sub(ob->center, cam);
	float t_hitcap = dot_product(p, ob->vector) / denom;
	// float t_hit = dot_product(c, ob->vector) / denom;
	// float t_hitbcap = dot_product(p1, ob->vector) / denom;
	// if (t_hitcap < T_MIN || t_max < t_hitcap)
	// {
		ob->ob_hit.t = t_hitcap;
		ob->ob_hit.p = vector_add(cam, vector_mul(v, ob->ob_hit.t));
		ob->ob_hit.normal = ob->vector;
	// }
	// printf("hittcap , center, hitbcap : %f, %f, %f\n", t_hitcap, t_hit, t_hitbcap);
	return (ob->index);
}

int	hit_cylinder(t_object *ob, t_vector v, t_vector cam, float t_max)
{
	t_vector	oc;
	float		sdis;
	(void)t_max;

	oc = vector_sub(cam, ob->center);
	ob->ob_hit.a = pow(dot_product(v, v), 2) - pow(dot_product(v, ob->vector), 2);
	ob->ob_hit.b = (dot_product(v, oc) - dot_product(v, ob->vector) * dot_product(oc, ob->vector));
	ob->ob_hit.c = dot_product(oc, oc) - pow(dot_product(oc, ob->vector), 2) - pow(ob->radius, 2);
	ob->ob_hit.dis = (pow(ob->ob_hit.b, 2)) - (ob->ob_hit.a * ob->ob_hit.c);
	sdis = sqrt(ob->ob_hit.dis);
	if (ob->ob_hit.dis < 0)
		return (-1);
	return (hit_caps(ob, sdis, v, cam, t_max));
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