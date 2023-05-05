/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:36:44 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 23:39:20 by npiya-is         ###   ########.fr       */
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

t_color	generate_color(t_vector lower)
{
	t_vector	unit;
	t_color		c1;
	t_color		c2;
	t_color		c3;
	float		t;

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

	vec = vector_add(cam, vector_mul(dir, t));
	vec = vector_normalize(vector_sub(vec, ob.center));
	ret = (t_color){(vec.x + 1) * 0.5, (vec.y + 1) * 0.5, (vec.z + 1) * 0.5};
	return (ret);
}

t_color	translate_color(t_color *c)
{
	t_color	nc;

	nc.r = clamp(sqrt(c->r), 0.0, 0.99) * 255.999;
	nc.g = clamp(sqrt(c->g), 0.0, 0.99) * 255.999;
	nc.b = clamp(sqrt(c->b), 0.0, 0.99) * 255.999;
	free(c);
	return (nc);
}
