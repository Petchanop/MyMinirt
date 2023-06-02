/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:19 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/02 22:56:48 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// origin = cpoint
//dir = direction;
//N = at(t);
//ray()origin = cpoint, dir = dir
// ray_dir
// ray_color
t_color	texture_color(t_cam *c, t_ray r, t_object *ob, int depth)
{
	t_color		ncolor;
	t_ray		reflec;
	t_vector	s;
	int			idx;

	ncolor = (t_color){0, 0, 0};
	reflec = r;
	idx = c->id_hit;
	s = isreflect(r.dir, r.normal);
	s = vector_normalize(s);
	if ((dot_product(c->ray.dir, s) > 0))
		ob[idx].tn += compute_specular(c, c->ray.dir, s);
	if (!strcmp(ob[idx].texture, "df"))
		ncolor = ray_color(c, r, ob, depth - 1);
	else if (!strcmp(ob[idx].texture, "mt"))
	{
		reflec = metal_reflec(&ob[idx], c->ray.dir);
		ncolor = ray_color(c, reflec, ob, depth - 1);
	}
	else
		ncolor = ray_color(c, r, ob, depth - 1);
	ncolor = color_multiply(ob[idx].color, ncolor);
	ncolor = color_multiply(c->light.color, color_mul(ncolor, ob[idx].tn));
	return (ncolor);
}

t_color	ray_color(t_cam *c, t_ray ca, t_object *ob, int depth)
{
	t_ray		r;
	t_color		ncolor;
	int			idx;

	ncolor = (t_color){0, 0, 0};
	if (depth <= 0)
		return (ncolor);
	idx = find_objecthit(c, ca, ob);
	c->id_hit = -1;
	c->t_max = T_MAX;
	if (idx > -1 && (ob[idx].ob_hit.t != 0.000))
	{
		c->id_hit = idx;
		r.dir = light_dir(ob[idx], c);
		r.origin = ob[idx].ob_hit.p;
		r.normal = ob[idx].ob_hit.normal;
		ob[idx].tn = c->ambient.bright_ratio;
		ob[idx].tn *= compute_shade(c, r.normal, r.dir);
		if (is_shadow(c, r, ob) != -1)
			return (ncolor);
		return (texture_color(c, r, ob, depth));
	}
	return (generate_color(ca.dir));
}

t_vector	random_hemisphere(t_vector normal)
{
	t_vector	u;

	u = vector_normalize(rand_in_sphere());
	if (dot_product(u, normal) > 0)
		return (u);
	else
		return (vector_mul(u, -1));
}
