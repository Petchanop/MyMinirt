/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:52:28 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 23:44:32 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_light(t_light *light)
{
	light->l = "L";
	light->point = (t_vector){8, 10, -10, 0};
	light->vector = (t_vector){0, 0, 1, 0};
	light->color = (t_color){200 / 255.999, 200 / 255.999, 255 / 255.999};
	light->bright_ratio = 0.8;
	light->dir = vector_normalize(light->point);
}

void	init_ambient(t_light *light)
{
	light->l = "A";
	light->bright_ratio = 0.8;
	light->color = (t_color){1, 0.5, 0.5};
}

t_vector	light_dir(t_object ob, t_cam *c)
{
	t_vector	l;

	l = vector_sub(c->light.point, vector_normalize(ob.ob_hit.p));
	l = vector_normalize(l);
	return (l);
}
