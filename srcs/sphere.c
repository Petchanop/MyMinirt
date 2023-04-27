/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:44:08 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/27 00:05:23 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	isfront_face(t_vector v, t_vector outward, t_object *ob)
{
	if (dot_product(v, outward) > 0)
		ob->ob_hit.normal = vector_mul(outward, -1);
	else
		ob->ob_hit.normal = outward;
	return (ob->ob_hit.normal);
}

int	hit(t_object *ob, float sdis, t_vector v, t_vector cam, float t_max)
{
	t_vector	outward;
	float		root;

	root = ((-ob->ob_hit.b - sdis) / ob->ob_hit.a);
	if (root < T_MIN || t_max < root)
	{
		root = (-ob->ob_hit.b + sdis) / ob->ob_hit.a;
		if (root < T_MIN || t_max < root)
			return (-1);
	}
	t_max = root;
	ob->ob_hit.t = root;
	ob->ob_hit.p = vector_add(cam, vector_mul(v, ob->ob_hit.t));
	outward = vector_sub(ob->ob_hit.p, ob->center);
	outward = vector_normalize(outward);
	ob->ob_hit.normal = vector_normalize(isfront_face(v, outward, ob));
	return (ob->index);
}

int	hit_sphere(t_object *ob, t_vector v, t_vector cam, float t_max)
{
	t_vector	oc;
	float		sdis;

	oc = vector_sub(cam, ob->center);
	ob->ob_hit.a = dot_product(v, v);
	ob->ob_hit.b = dot_product(oc, v);
	ob->ob_hit.c = pow(vector_length(oc), 2) - (pow(ob->radius, 2));
	ob->ob_hit.dis = (pow(ob->ob_hit.b, 2)) - (ob->ob_hit.a * ob->ob_hit.c);
	sdis = sqrt(ob->ob_hit.dis);
	if (ob->ob_hit.dis < 0)
		return (-1);
	else
		return (hit(ob, sdis, v, cam, t_max));
}

int	hit_object(t_object *ob, t_vector v, t_vector cam, float t_max)
{
	if (!strcmp(ob->type, "sp"))
		return (hit_sphere(ob, v, cam, t_max));
	else if (!strcmp(ob->type, "cy"))
		return (hit_cylinder(ob, v, cam, t_max));
	else if (!strcmp(ob->type, "pl"))
		return (hit_plane(ob, v, cam, t_max));
	else if (!strcmp(ob->type, "dk"))
	{
		if (hit_plane(ob, v, cam, t_max) != -1)
			return (hit_disk(ob, v, cam, ob->center, ob->ob_hit.t));
	}
	return (-1);
}

//unit_vector == vector_normalize