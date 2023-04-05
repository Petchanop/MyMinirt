/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:00:31 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/05 02:41:16 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	diffuse_mat(t_object ob)
{
	t_vector	n_p;

	n_p = vector_add(ob.ob_hit.p, ob.ob_hit.normal);
	n_p = vector_add(n_p, vector_normalize(random_hemisphere(ob.ob_hit.normal)));
	n_p = vector_sub(n_p, ob.ob_hit.p);
	return (n_p);
}

t_vector	isreflect(t_vector v, t_vector n)
{
	t_vector	dot_n;

	dot_n = vector_mul(n, 2 * dot_product(v, n));
	return (vector_sub(v, dot_n));
}

int	near_zero(t_vector v)
{
	float	s;

	s = 0.01;
	return ((fabs(v.x) < s) && (fabs(v.y) < s) && (fabs(v.z) < s));
}

t_ray	scatter_lambertian(t_object *ob, t_vector cam)
{
	t_vector	scatter;
	t_ray		scatered;
	t_vector	reflec;
	t_vector	fuzz;

	// scatter = vector_add(ob->ob_hit.normal, vector_normalize(rand_in_sphere()));
	reflec = isreflect(vector_normalize(cam), ob->ob_hit.normal);
	// scatter = vector_add(vector_normalize(ob->ob_hit.p), vector_normalize(ob->ob_hit.normal));
	// scatter = vector_add(vector_normalize(ob->ob_hit.p), ob->ob_hit.normal);
	scatter = vector_add(ob->ob_hit.p, ob->ob_hit.normal);
	// scatter = vector_add(ob->ob_hit.p, reflec);
	if (near_zero(scatter))
	{
		scatter = ob->ob_hit.normal;
		printf("scatter : %f, %f, %f\n", scatter.x, scatter.y, scatter.z);
	}
	// printf("dot : %d\n", dot_product(reflec, ob->ob_hit.normal) > 0);
	if ((dot_product(reflec, ob->ob_hit.normal) > 0))
		scatter =  reflec;
	if (!strcmp(ob->reflec, "fu"))
	{
		fuzz = vector_mul(rand_in_sphere(), rand_between(0.1, 1));
		scatered = (t_ray){ob->ob_hit.p, vector_add(scatter, fuzz) , ob->ob_hit.t};
	}
	else
		scatered = (t_ray){ob->ob_hit.p, scatter, ob->ob_hit.t};
	return (scatered);
}

t_color	metal_reflec(t_ray r_in, t_object *ob, int depth)
{
	t_vector	v_reflec;

	v_reflec = isreflect(vector_normalize(r_in.dir), ob->ob_hit.normal);
	// scattered = scatter_lambertian(ob);
	r_in.origin = ob->ob_hit.p;
	if ((dot_product(v_reflec, ob->ob_hit.normal) > 0))
	{
		r_in.dir = v_reflec;
		return (ray_color(r_in.origin, r_in.dir, ob, depth - 1));
	}
	return ((t_color){0, 0, 0});
}

//color_mul(color_add(ob[i].color, ray_color(ob[i].ob_hit.p, n_p, ob, depth - 1)), 0.5);
