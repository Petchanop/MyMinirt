/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:20:52 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 23:45:28 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_object(t_object *ob, t_vector center, t_vector n, t_color rgb)
{
	ob->type = "sp";
	ob->center = center;
	ob->color = rgb;
	ob->vector = vector_normalize(n);
}

void	init_cylinder(t_object *ob, t_vector center, t_vector n, t_color rgb)
{
	t_vector	half_height;

	ob->type = "cy";
	ob->center = center;
	ob->color = rgb;
	ob->vector = vector_normalize(n);
	half_height = vector_mul(ob->vector, ob->height / 2);
	ob->t_cap = vector_add(half_height, ob->center);
	ob->b_cap = vector_sub(ob->center, half_height);
	ob->diff = vector_sub(ob->b_cap, ob->t_cap);
}

void	init_plane(t_object *ob, t_vector center, t_vector n, t_color rgb)
{
	ob->type = "pl";
	ob->center = center;
	ob->color = rgb;
	ob->vector = n;
}

void	init_disk(t_object *ob, t_vector center, t_vector n, t_color rgb)
{
	ob->type = "dk";
	ob->center = center;
	ob->color = rgb;
	ob->vector = vector_normalize(n);
}

void	init_type(t_object *ob, char *type, char *reflec)
{
	ob->texture = type;
	ob->reflec = reflec;
	ob->tn = 1;
}
