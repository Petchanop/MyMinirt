/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:44:08 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/02 19:36:52 by npiya-is         ###   ########.fr       */
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

int	hit(t_object *ob, float sdis, t_ray r, float t_max)
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
	ob->ob_hit.p = vector_add(r.origin, vector_mul(r.dir, ob->ob_hit.t));
	outward = vector_sub(ob->ob_hit.p, ob->center);
	outward = vector_normalize(outward);
	ob->ob_hit.normal = vector_normalize(isfront_face(r.dir, outward, ob));
	return (ob->index);
}

int	hit_sphere(t_object *ob, t_ray r, float t_max)
{
	t_vector	oc;
	float		sdis;

	oc = vector_sub(r.origin, ob->center);
	ob->ob_hit.a = dot_product(r.dir, r.dir);
	ob->ob_hit.b = dot_product(oc, r.dir);
	ob->ob_hit.c = pow(vector_length(oc), 2) - (pow(ob->radius, 2));
	ob->ob_hit.dis = (pow(ob->ob_hit.b, 2)) - (ob->ob_hit.a * ob->ob_hit.c);
	sdis = sqrt(ob->ob_hit.dis);
	if (ob->ob_hit.dis < 0)
		return (-1);
	else
		return (hit(ob, sdis, r, t_max));
}
//unit_vector == vector_normalize
