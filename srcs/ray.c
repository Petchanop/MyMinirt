/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:19 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/26 18:15:42 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// origin = cpoint
//dir = direction;
//N = at(t);
//ray()origin = cpoint, dir = dir
// ray_dir
// ray_color
t_color	ray_color(t_cam *c, t_vector cam, t_vector dir, t_object *ob, int depth)
{
	t_vector	n_p;
	t_vector	l;
	t_vector	s;
	t_color		ncolor;
	float		tn;
	float		len;
	int			i;
	int		t;
	int		idx;

	i = 0;
	tn = 1;
	idx = -1;
	ncolor = (t_color){0, 0, 0};
	n_p = (t_vector){0, 0, 0, 0};
	if (depth <= 0)
		return (ncolor);
	while (ob[i].type)
	{
		t = hit_object(&ob[i], dir, cam, c->t_max);
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
			l = diffuse_mat(ob[idx], c, dir);
			len = vector_length(l);
			t_vector normal = ob[idx].ob_hit.normal;
			t_vector n_p = ob[idx].ob_hit.p;
			tn = c->light.bright_ratio * pow(fmax(0, dot_product(vector_normalize(normal), l)), 2);
			if (is_shadow(c, n_p, l, ob, idx) != -1)
				return (ncolor);
			s = isreflect(l, normal);
			s = vector_normalize(s);
			if ((dot_product(dir, s) > 0))
				tn += c->light.bright_ratio * pow(fmax(0, dot_product(dir, s)), 2);
			if (!strcmp(ob[idx].texture, "df"))
				ncolor = ray_color(c, n_p, l, ob, depth - 1);
			else if (!strcmp(ob[idx].texture, "mt"))
				ncolor = metal_reflec(c, ob, &ob[idx], dir, depth - 1);
			else
				ncolor = ray_color(c, n_p, l, ob, depth - 1);
			ncolor = color_multiply(ob[idx].color, ncolor);
			return (color_mul(ncolor, tn));
		}
	}
	c->t_max = T_MAX;
	return (generate_color(dir));
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