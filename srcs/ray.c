/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:19 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/06 17:22:09 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// origin = cpoint
//dir = direction;
//N = at(t);

t_vector	ray_dir(t_cam *cam, t_vector r, float u, float v)
{
	t_vector	v_h;
	t_vector	v_v;
	t_vector	lower;

	v_h = vector_mul(cam->v_h, u);
	v_v = vector_mul(cam->v_v, v);
	lower = vector_add(cam->lower, v_h);
	lower = vector_add(lower, v_v);
	lower = vector_sub(lower, r);
	lower = vector_normalize(vector_sub(lower, cam->cpoint));
	return (lower);
}

//ray()origin = cpoint, dir = dir
// ray_dir
// ray_color
t_color	ray_color(t_cam *c, t_vector cam, t_vector dir, t_object *ob, int depth)
{
	t_vector	n_p;
	t_color		ncolor;
	int			i;
	int		t;
	int		idx;

	i = 0;
	idx = -1;
	ncolor = (t_color){0, 0, 0};
	n_p = (t_vector){0, 0, 0, 0};
	if (depth <= 0)
		return ((t_color){0, 0, 0});
	while (ob[i].type)
	{
		t = hit_object(&ob[i], dir, cam, c->t_max);
		if (t > -1)
		{
			c->t_max = ob[t].ob_hit.t;
			idx = t;
		}
		i++;
	}
	if (idx > -1)
	{
		if (ob[idx].ob_hit.t != 0.000)
		{
			c->t_max = T_MAX;
			if (!strcmp(ob[idx].texture, "df"))
			{
				n_p = diffuse_mat(ob[idx]);
				ncolor = ray_color(c, ob[idx].ob_hit.p, n_p, ob, depth - 1);
			}
			else if (!strcmp(ob[idx].texture, "mt"))
				ncolor = metal_reflec(c, ob, &ob[idx], dir, depth);
			else
				ncolor = color_mul(ray_color(c, ob[idx].ob_hit.p, n_p, ob, depth - 1), 0.5);
			ncolor = color_multiply(ob[idx].color, ncolor);
			return (ncolor);
		}
	}
	c->t_max = T_MAX;
	return (generate_color(dir, t));
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