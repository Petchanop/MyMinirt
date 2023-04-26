/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:31:47 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/26 14:18:26 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	create_background(t_cam *cam, t_object *ob, t_vars *data, t_color color)
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
			// if (x < 550 && y > 250)
			// {
				// printf("x , y : %d, %d ", x, y);
				color = antialiasing(cam, ob, x, y);
				c = convert_to_int(color);
				put_pixel(&data->img, x, y, c);
			// }
			x--;
		}
		y--;
	}
}