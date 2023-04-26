/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:59:05 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/26 15:06:05 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	compute_normal(t_object *ob, t_vector t)
{
	t_vector	obj_normal;
	float		radius;
	(void)ob;

	radius = t.x * t.x + t.z * t.z;
	if (radius < 1 && t.y >= 1 - EPSILON)
		obj_normal = (t_vector){0, 1, 0, 0};
	else if (radius < 1 && t.y <= 0 + EPSILON)
		obj_normal = (t_vector){0, -1, 0, 0};
	else
		obj_normal = (t_vector){t.x, 0, t.z, 0};
	return (obj_normal);
}

int	check_end_cap(t_vector cam, t_vector v, double t)
{
	double	x;
	double	z;
	double	radius;

	x = cam.x + v.x * t;
	z = cam.z + v.z * t;
	radius = x * x + z * z;
	if (radius <= 1)
		return (1);
	else
		return (0);
}

float	find_caps(t_vector v, t_vector cam)
{
	float	t[2];
	float	inter_t[2];

	inter_t[0] = INFINITY;
	inter_t[1] = INFINITY;
	t[0] = -cam.y / v.y;
	t[1] = (1 - cam.y) / v.y;
	if (t[0] > 0 && check_end_cap(cam, v, t[0]))
		inter_t[0] = t[0];
	if (t[1] > 0 && check_end_cap(cam, v, t[1]))
		inter_t[1] = t[1];
	return (min(inter_t[0], inter_t[1]));
}

int	hit_body(t_object *ob, float sdis, t_vector v, t_vector cam, float t_max)
{
	float		t0;
	float		t1;
	float		root;

	t0 = ((-ob->ob_hit.b - sdis) / 2 * ob->ob_hit.a);
	t1 = (-ob->ob_hit.b + sdis) / 2 * ob->ob_hit.a;
	if (t1 < 0)
		return (-1);
	t0 = cam.y + v.y * t0;
	t1 = cam.y + v.y * t1;
	if (t0 < 0 || t0 > 1)
		t0 = INFINITY;
	if (t1 < 0 || t1 > 1)
		t1 = INFINITY;
	if (!t1 && !t0)
		return (-1);
	if (t0 < t1 && t0 > 0)
		root = t0;
	else
		root = t1;
	t_max = root;
	float t_cap = find_caps(v, cam);	
	ob->ob_hit.t = min(t_cap, root);
	ob->ob_hit.p = vector_add(cam, vector_mul(v, ob->ob_hit.t));
	ob->ob_hit.normal = compute_normal(ob, ob->ob_hit.p);
	t_vector bot = ob->center;
	bot.y = ob->center.y - (ob->height / 2); 
	// ob->ob_hit.normal = dot_product(vector_sub(ob->ob_hit.p, bot), cam); 
	return (ob->index);
}

//  t = dot((hit_pt - cy.bottom_center), cy.ori); // cy.ori should be normalized and so has the length of 1.
//     pt = cy.bottom_center + t * cy.ori;
//     surface_normal = normalize(hit_pt - pt)));

int	hit_cylinder(t_object *ob, t_vector v, t_vector cam, float t_max)
{
	t_vector	oc;
	float		sdis;

	// oc = ob->center;
	// // oc.y += ob->height / 2;
	// if (hit_plane(ob, v, cam, t_max) != -1)
	// {
	// 	t_vector	p = vector_sub(oc, cam);
	// 	if (hit_disk(ob, v, cam, p, t_max) > -1)
	// 		return (ob->index);
	// 	oc.y -= ob->height;
	// 	return (hit_disk(ob, v, cam, p, t_max));
	// }
	// else
	// 	return (-1);
	oc = vector_sub(cam, ob->center);
	ob->ob_hit.a = pow(v.x, 2) + pow(v.z, 2);
	ob->ob_hit.b = (2 * v.x * cam.x) + ( 2* v.z * cam.z);
	ob->ob_hit.c = pow(cam.x, 2) + pow(cam.z, 2) - 1;
	ob->ob_hit.dis = (pow(ob->ob_hit.b, 2)) - (4 * ob->ob_hit.a * ob->ob_hit.c);
	sdis = sqrt(ob->ob_hit.dis);
	if (ob->ob_hit.dis < 0)
		return (-1);
	else
		return (hit_body(ob, sdis, v, cam, t_max));
}
