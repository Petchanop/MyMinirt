/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:44:08 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/05 13:04:42 by npiya-is         ###   ########.fr       */
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

float	hit(t_object *ob, float sdis, t_vector v, t_vector cam)
{
	t_vector	outward;
	float		root;

	root = ((-ob->ob_hit.b - sdis) / ob->ob_hit.a);
	if (root < T_MIN || T_MAX < root)
	{
		root = (-ob->ob_hit.b + sdis) / ob->ob_hit.a;
		if (root < T_MIN || T_MAX < root)
			return (0);
	}
	ob->ob_hit.t = root;
	ob->ob_hit.p = vector_add(cam, vector_mul(v, ob->ob_hit.t));
	outward = vector_div(vector_sub(ob->ob_hit.p, ob->center), ob->radius);
	ob->ob_hit.normal = isfront_face(v, outward, ob);
	return (root);
}

float	hit_object(t_object *ob, t_vector v, t_vector cam)
{
	t_vector	oc;
	float		sdis;

	oc = vector_sub(cam, ob->center);
	ob->ob_hit.a = vector_length(v);
	ob->ob_hit.b = dot_product(oc, v);
	ob->ob_hit.c = pow(vector_length(oc), 2) - (pow(ob->radius, 2));
	ob->ob_hit.dis = (pow(ob->ob_hit.b, 2)) - (ob->ob_hit.a * ob->ob_hit.c);
	sdis = sqrt(ob->ob_hit.dis);
	if (ob->ob_hit.dis < 0)
		return (0);
	else
		return (hit(ob, sdis, v, cam));
}

//unit_vector == vector_normalize