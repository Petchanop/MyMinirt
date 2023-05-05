/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:38:39 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 23:43:50 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	color_mul(t_color col, float t)
{
	col.r *= t;
	col.g *= t;
	col.b *= t;
	return (col);
}

t_color	color_multiply(t_color c1, t_color c2)
{
	t_color	c;

	c.r = c1.r * c2.r;
	c.g = c1.g * c2.g;
	c.b = c1.b * c2.b;
	return (c);
}

t_color	color_div(t_color c, float a)
{
	t_color	ret;

	ret.r = c.r / a;
	ret.g = c.g / a;
	ret.b = c.b / a;
	return (ret);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	c;

	c.r = c1.r + c2.r;
	c.g = c1.g + c2.g;
	c.b = c1.b + c2.b;
	return (c);
}

t_color	color_sub(t_color c1, t_color c2)
{
	t_color	c;

	c.r = c1.r - c2.r;
	c.g = c1.g - c2.g;
	c.b = c1.b - c2.b;
	return (c);
}
