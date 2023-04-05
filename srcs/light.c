/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:52:28 by npiya-is          #+#    #+#             */
/*   Updated: 2023/03/25 21:00:34 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void init_light(t_light light)//, t_color color, t_point lpoint, t_vector vector)
{
	light.point = (t_vector){-40, 50, 0};
	light.vector = (t_vector){0, 0, 1};
	light.color = (t_color){10, 0, 255};
	light.bright_ratio = 0.6;
	light.m_lab = vector_sub(light.point, light.vector);
}