/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:15:18 by npiya-is          #+#    #+#             */
/*   Updated: 2023/03/23 23:23:58 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x <= 1920 && y <= 1080)
		my_mlx_pixel_put(data, x, y, color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	write_line(t_vars vars, t_point point[2], t_color color)
{
	t_point	begin;
	t_point	diff;
	t_point	step;
	t_point	stop;
	(void)color;

	begin = point[0];
	stop = point[1];
	diff = find_dxdy(begin, stop);
	step.y = diff.y / find_stepxy(diff);
	step.x = diff.x / find_stepxy(diff);
	while (check_point(begin, stop, step))
	{
		my_mlx_pixel_put(&vars.img, begin.x, begin.y, 61440);
		begin.y += step.y;
		begin.x += step.x;
	}
}