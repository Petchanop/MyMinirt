/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:28:08 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 02:04:43 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	compute_shade(t_cam *c, t_vector p, t_vector s)
{
	float	tn;
	float	dot;

	dot = dot_product(p, s);
	tn = c->light.bright_ratio * fmax(0, dot);
	return (tn);
}

float	compute_specular(t_cam *c, t_vector p, t_vector s)
{
	float	dot;
	float	tn;

	dot = dot_product(vector_normalize(p), s);
	tn = c->light.bright_ratio * pow(fmax(0, dot), 4);
	return (tn);
}
