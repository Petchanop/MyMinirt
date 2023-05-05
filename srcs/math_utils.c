/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:08:55 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 23:45:08 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	random_float( void )
{
	float	n;

	n = (float)rand() / RAND_MAX;
	return (n);
}

float	rand_between(float min, float max)
{
	float	n;

	n = min + (max - min) * random_float();
	return (n);
}

float	clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}
