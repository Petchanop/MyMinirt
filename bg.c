/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:31:47 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/12 00:54:36 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

void	create_background(t_cam *cam, t_object *ob, t_data *data, t_color color)
{
	int	x;
	int	y;
	int	c;

	y = SCENCE_HEIGHT - 1;
	while (y)
	{
		x = SCENCE_WIDTH - 1;
		while (x)
		{
			color = antialiasing(cam, ob, x, y);
			c = convert_to_int(color);
			put_pixel(data, x, y, c);
			x--;
		}
		y--;
	}
}

float	dis_from_sphere(t_vector current, t_object *ob, float r)
{
	return (vector_length(vector_sub(current, ob->center)) - r);
}
