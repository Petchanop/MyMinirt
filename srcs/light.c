/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:52:28 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/18 18:12:42 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_light(t_light *light)
{
	light->l = "L";
	light->point = (t_vector){-5, 10, 4, 0};
	light->vector = (t_vector){1, 1, 1, 0};
	light->color = (t_color){10 / 255.999, 0, 255 / 255.999};
	light->bright_ratio = 0.8;//[0, 1]
	light->dir = vector_normalize(light->point);
}

void	init_ambient(t_light *light)
{
	light->l = "A";
	light->bright_ratio = 0.2;
	light->color = (t_color){255, 255, 255};
}

t_color	light_color(t_object *ob, t_cam *c, int depth)
{
	t_vector	reflec;
	(void)depth;

	reflec = isreflect(vector_normalize(c->light.dir), ob->ob_hit.normal);
	return (ob->color);
	// if (dot_product(reflec, ob->ob_hit.normal) > 0)
}