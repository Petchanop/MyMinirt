/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:28:08 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/04 18:33:00 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	compute_shade(t_cam *c, t_vector p, t_vector s)
{
	float	tn;
	float	dot;

	dot = dot_product(vector_normalize(p), s);
	tn = c->light.bright_ratio * pow(fmax(0, dot), 2);
	return (tn);
}
