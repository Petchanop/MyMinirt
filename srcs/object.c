/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:20:52 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/05 00:21:06 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_sphere(t_object *ob, char **c, char **col)
{
	t_vector	center;
	t_color		rgb;

	center = (t_vector){ft_atof(c[0]), ft_atof(c[1]), ft_atof(c[2]), 0};
	rgb = (t_color){ft_atof(col[0]), ft_atof(col[1]), ft_atof(col[2])};
	ob->center = center;
	ob->color.r = rgb.r / 255.999;
	ob->color.g = rgb.g / 255.999;
	ob->color.b = rgb.b / 255.999;
}

void	init_cylinder(t_object *ob, char **c, char **v, char **col)
{
	t_vector	center;
	t_vector	n;
	t_vector	half_height;
	t_color		rgb;

	center = (t_vector){ft_atof(c[0]), ft_atof(c[1]), ft_atof(c[2]), 0};
	n = (t_vector){ft_atof(v[0]), ft_atof(v[1]), ft_atof(v[2]), 0};
	rgb = (t_color){ft_atof(col[0]), ft_atof(col[1]), ft_atof(col[2])};
	ob->center = center;
	ob->color.r = rgb.r / 255.999;
	ob->color.g = rgb.g / 255.999;
	ob->color.b = rgb.b / 255.999;
	ob->vector = vector_normalize(n);
	half_height = vector_mul(ob->vector, ob->height / 2);
	ob->t_cap = vector_add(half_height, ob->center);
	ob->b_cap = vector_sub(ob->center, half_height);
	ob->diff = vector_sub(ob->b_cap, ob->t_cap);
}

void	init_plane(t_object *ob, char **c, char **v, char **col)
{
	t_vector	center;
	t_vector	n;
	t_color		rgb;

	center = (t_vector){ft_atof(c[0]), ft_atof(c[1]), ft_atof(c[2]), 0};
	n = (t_vector){ft_atof(v[0]), ft_atof(v[1]), ft_atof(v[2]), 0};
	rgb = (t_color){ft_atof(col[0]), ft_atof(col[1]), ft_atof(col[2])};
	ob->center = center;
	ob->color.r = rgb.r / 255.999;
	ob->color.g = rgb.g / 255.999;
	ob->color.b = rgb.b / 255.999;
	ob->vector = vector_normalize(n);
}

void	init_disk(t_object *ob, t_vector center, t_vector n, t_color rgb)
{
	ob->type = "dk";
	ob->center = center;
	ob->color = rgb;
	ob->vector = vector_normalize(n);
}

void	init_cone(t_object *ob, char **c, char **v, char **col)
{
	t_vector	center;
	t_vector	n;
	t_vector	half_height;
	t_color		rgb;

	center = (t_vector){ft_atof(c[0]), ft_atof(c[1]), ft_atof(c[2]), 0};
	n = (t_vector){ft_atof(v[0]), ft_atof(v[1]), ft_atof(v[2]), 0};
	rgb = (t_color){ft_atof(col[0]), ft_atof(col[1]), ft_atof(col[2])};
	ob->center = center;
	ob->color.r = rgb.r / 255.999;
	ob->color.g = rgb.g / 255.999;
	ob->color.b = rgb.b / 255.999;
	ob->vector = vector_normalize(n);
	half_height = vector_mul(ob->vector, ob->height / 2);
	ob->t_cap = vector_add(half_height, ob->center);
	ob->b_cap = vector_sub(ob->center, half_height);
	ob->diff = vector_sub(ob->b_cap, ob->t_cap);
	ob->k = ob->radius / ob->height;
	ob->k = 1 + pow(ob->k, 2);
}
