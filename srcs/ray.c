/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:19 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/04 16:03:00 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// origin = cpoint
//dir = direction;
//N = at(t);
//ray()origin = cpoint, dir = dir
// ray_dir
// ray_color
t_color	ray_color(t_cam *c, t_ray ca, t_object *ob, int depth)
{
	t_ray		r;
	t_vector	s;
	t_color		ncolor;
	float		tn;
	int			i;
	int		t;
	int		idx;

	i = 0;
	tn = 1;
	idx = -1;
	ncolor = (t_color){0, 0, 0};
	if (depth <= 0)
		return (ncolor);
	while (ob[i].type)
	{
		t = hit_object(&ob[i], ca.dir, ca.origin, c->t_max);
		if (t > -1)
		{
			c->t_max = ob[i].ob_hit.t;
			idx = t;
		}
		i++;
	}
	if (idx > -1)
	{
		c->t_max = T_MAX;
		if (ob[idx].ob_hit.t != 0.000)
		{
			r.dir = light_dir(ob[idx], c);
			r.origin = ob[idx].ob_hit.p;
			r.normal = ob[idx].ob_hit.normal;
			tn = c->light.bright_ratio * pow(fmax(0, dot_product(vector_normalize(r.normal), r.dir)), 2);
			if (is_shadow(c, r, ob) != -1)
				return (ncolor);
			s = isreflect(r.dir, r.normal);
			s = vector_normalize(s);
			if ((dot_product(ca.dir, s) > 0))
				tn += c->light.bright_ratio * pow(fmax(0, dot_product(ca.dir, s)), 2);
			if (!strcmp(ob[idx].texture, "df"))
				ncolor = ray_color(c, r, ob, depth - 1);
			else if (!strcmp(ob[idx].texture, "mt"))
				ncolor = metal_reflec(c, ob, &ob[idx], ca.dir, depth - 1);
			else
				ncolor = ray_color(c, r, ob, depth - 1);
			ncolor = color_multiply(ob[idx].color, ncolor);
			return (color_mul(ncolor, tn));
		}
	}
	c->t_max = T_MAX;
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

// bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {