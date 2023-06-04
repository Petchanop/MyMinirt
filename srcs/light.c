/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:52:28 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/05 00:19:04 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_light(t_light *light, t_vector c, t_color col, float ratio)
{
	light->point = c;
	light->vector = (t_vector){0, 0, 1, 0};
	light->color = (t_color){col.r / 255.999, col.g / 255.999, col.b / 255.999};
	light->bright_ratio = ratio;
	light->dir = vector_normalize(light->point);
}

void	init_ambient(t_light *light, float ratio, t_color color)
{
	light->bright_ratio = ratio;
	light->color = color;
}

t_vector	light_dir(t_object ob, t_cam *c)
{
	t_vector	l;
	t_vector	n;

	n = vector_add(ob.ob_hit.p, ob.ob_hit.normal);
	l = vector_sub(c->light.point, n);
	l = vector_normalize(l);
	return (l);
}
