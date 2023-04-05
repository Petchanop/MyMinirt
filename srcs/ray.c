/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:19 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/05 02:49:00 by npiya-is         ###   ########.fr       */
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
	return (lower);
}

//ray()origin = cpoint, dir = dir
// ray_dir
// ray_color
t_color	ray_color(t_vector cam, t_vector p, t_object *ob, int depth)
{
	t_vector	dir;
	t_vector	n_p;
	t_ray		r_in;
	t_color		ncolor;
	int			i;
	float		t;

	dir = vector_normalize(vector_sub(p, cam));
	i = 0;
	ncolor = (t_color){0, 0, 0};
	n_p = (t_vector){0, 0, 0, 0};
	if (depth <= 0)
		return ((t_color){0, 0, 0});
	while (ob[i].type)
	{
		t = hit_object(&ob[i], dir, cam);
		if (t != 0.000)
		{
			if (!strcmp(ob[i].texture, "df"))
			{
				n_p = diffuse_mat(ob[i]);
				ncolor = ray_color(ob[i].ob_hit.p, n_p, ob, depth - 1);
			}
			else if (!strcmp(ob[i].texture, "mt"))
			{
				// r_in = (t_ray){ob[i].ob_hit.normal, ob[i].ob_hit.p, t};
				r_in = scatter_lambertian(&ob[i], dir);
				// ncolor = metal_reflec(r_in, &ob[i], depth);
				ncolor = ray_color(r_in.origin, r_in.dir, ob, depth - 1);
			}
			else
				ncolor = color_mul(ray_color(ob[i].ob_hit.p, n_p, ob, depth - 1), 0.5);
			ncolor = color_multiply(ob[i].color, ncolor);
			return (ncolor);
		}
		i++;
	}	
	return (generate_color(p, t));
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