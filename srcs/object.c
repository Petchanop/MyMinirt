/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:20:52 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/27 16:38:19 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_object(t_object *ob, t_vector center, t_vector n, t_color rgb)
{
	ob->type = "sp";
	ob->center = center;
	ob->color = rgb;
	ob->vector = n;
}

void	init_cylinder(t_object *ob, t_vector center, t_vector n, t_color rgb)
{
	ob->type = "cy";
	ob->center = center;
	ob->t_cap = (t_vector){center.x, center.y + (ob->height / 2), center.z, 0};
	ob->b_cap = (t_vector){center.x, center.y - (ob->height / 2), center.z, 0};
	ob->color = rgb;
	ob->vector = n;
	printf("t_cap : %f, %f, %f\n", ob->t_cap.x, ob->t_cap.y, ob->t_cap.z);
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
	ob->vector = n;
}

void	init_type(t_object *ob, char *type, char *reflec)
{
	ob->texture = type;
	ob->reflec = reflec;
}

int	isclose(float f1, float f2)
{
	return (fabs(f1 - f2) < EPSILON);
}
// int	isintersection(t_vector point, t_point point, t_vector local, t_color color)