/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:31:47 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 21:17:22 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	create_scence(t_scence *sc, t_object *ob, t_vars *data, t_color color)
{
	int	x;
	int	y;
	int	c;

	y = sc->maxy;
	while (y > sc->miny)
	{
		x = sc->maxx;
		while (x > sc->minx)
		{
			color = antialiasing(&sc->c, ob, x, y);
			c = convert_to_int(color);
			pthread_mutex_lock(&data->mutex);
			put_pixel(&data->img, SCENCE_WIDTH - x, y, c);
			pthread_mutex_unlock(&data->mutex);
			x--;
		}
		y--;
	}
}

void	*render_scence(void *sc)
{
	t_scence	*scence;
	t_color		color;

	scence = sc;
	color = (t_color){0, 0, 0};
	create_scence(scence, scence->ob, scence->data, color);
	return (0);
}
