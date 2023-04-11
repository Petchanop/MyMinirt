/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:36:44 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/12 01:24:08 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	convert_to_int(t_color color)
{
	int	result;

	result = (color.b);
	result += ((int)color.g << 8);
	result += ((int)color.r << 16);
	return (result);
}

t_color	generate_color(t_vector lower, float t)
{
	t_vector	unit;
	t_color		c1;
	t_color		c2;
	t_color		c3;

	unit = vector_normalize(lower);
	t = 0.5 * (unit.y + 1);
	c1 = (t_color){1 * (1 - t), 1 * (1 - t), 1 * (1 - t)};
	c2 = (t_color){0.5 * t, 0.7 * t, 1 * t};
	c3 = (t_color){c1.r + c2.r, c1.g + c2.g, c1.b + c2.b};
	return (c3);
}

t_color	generate_obcolor(t_vector cam, t_object ob, t_vector dir, float t)
{
	t_vector	vec;
	t_color		ret;

	vec = vector_add(cam, vector_mul(dir, t));//r.at
	vec = vector_normalize(vector_sub(vec, ob.center));
	ret = (t_color){(vec.x + 1) * 0.5, (vec.y + 1) * 0.5, (vec.z + 1) * 0.5};
	return (ret);
}

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

t_color	color_add(t_color c1, t_color c2)
{
	t_color	c;

	c.r = c1.r + c2.r;
	c.g = c1.g + c2.g;
	c.b = c1.b + c2.b;
	return (c);
}

t_color	translate_color(t_color c)
{
	c.r = clamp(sqrt(c.r), 0.0, 0.99) * 255.999;
	c.g = clamp(sqrt(c.g), 0.0, 0.99) * 255.999;
	c.b = clamp(sqrt(c.b), 0.0, 0.99) * 255.999;
	return (c);
}
