/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:20:52 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/04 02:31:26 by npiya-is         ###   ########.fr       */
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
	printf("diff : %f, %f, %f\n", ob->diff.x, ob->diff.y, ob->diff.z);
	printf("cen : %f, %f, %f\n", ob->center.x, ob->center.y, ob->center.z);
	printf("top : %f, %f, %f\n", ob->t_cap.x, ob->t_cap.y, ob->t_cap.z);
	printf("bot : %f, %f, %f\n", ob->b_cap.x, ob->b_cap.y, ob->b_cap.z);
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
	printf("dis : %f, %f, %f\n", ob->center.x, ob->center.y, ob->center.z);

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