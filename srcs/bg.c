/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:31:47 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 18:46:06 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// void	create_background(t_cam *cam, t_object *ob, t_vars *data, t_color color)
// {
// 	int	x;
// 	int	y;
// 	int	c;

// 	y = SCENCE_HEIGHT - 1;
// 	while (y)
// 	{
// 		x = SCENCE_WIDTH - 1;
// 		while (x)
// 		{
// 			color = antialiasing(cam, ob, x, y);
// 			c = convert_to_int(color);
// 			put_pixel(&data->img, SCENCE_WIDTH - x, y, c);
// 			x--;
// 		}
// 		y--;
// 	}
// }

void	create_background(t_scence *sc, t_object *ob, t_vars *data, t_color color)
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
	create_background(scence, scence->ob, scence->data, color);
	return (0);
}

void	create_scence(t_cam *cam, t_object *ob, t_vars *data)
{
	pthread_t	th[8];
	t_scence	sc[8];
	int			i;
	int			j;
	int			sizex;
	int			minx;
	int			sizey;
	int			miny;
	int			dx;
	int			dy;

	i = 0;
	sizey = SCENCE_HEIGHT - 1;
	minx = 0;
	miny = 0;
	dx = (SCENCE_WIDTH - 1) / 4;
	dy = sizey / 2;
	sizex = dx;
	sc[0].ob = malloc(sizeof(t_object) * 7);
	sc[1].ob = malloc(sizeof(t_object) * 7);
	sc[2].ob = malloc(sizeof(t_object) * 7);
	sc[3].ob = malloc(sizeof(t_object) * 7);
	sc[4].ob = malloc(sizeof(t_object) * 7);
	sc[5].ob = malloc(sizeof(t_object) * 7);
	sc[6].ob = malloc(sizeof(t_object) * 7);
	sc[7].ob = malloc(sizeof(t_object) * 7);
	sc[0].id = 1;
	sc[1].id = 2;
	sc[2].id = 3;
	sc[3].id = 4;
	sc[4].id = 5;
	sc[5].id = 6;
	sc[6].id = 7;
	sc[7].id = 8;
	pthread_mutex_init(&data->mutex, NULL);
	while (i < 8)
	{
		sc[i].c = *cam;
		sc[i].data = data;
		sc[i].maxx = sizex;
		sc[i].maxy = sizey / 2;
		sc[i].minx = minx;
		sc[i].miny = miny;
		j = 0;
		while (ob[j].type)
		{
			sc[i].ob[j] = ob[j];
			j++;
		}
		// printf("id %d x : %d, %d y : %d, %d\n", i + 1, sizex, minx, sizey / 2, miny);
		sc[i].ob[j].type = NULL;
		minx += dx;	
		sizex +=  dx;
		if (i == 3)
		{
			miny += sizey / 2;
			sizey *= 2;
			minx = 0;
			dx = (SCENCE_WIDTH - 1) / 4;
			sizex = dx;
		}
		i++;
	}
	pthread_create(&th[0], NULL, &render_scence, &sc[0]);
	pthread_create(&th[1], NULL, &render_scence, &sc[1]);
	pthread_create(&th[2], NULL, &render_scence, &sc[2]);
	pthread_create(&th[3], NULL, &render_scence, &sc[3]);
	pthread_create(&th[4], NULL, &render_scence, &sc[4]);
	pthread_create(&th[5], NULL, &render_scence, &sc[5]);
	pthread_create(&th[6], NULL, &render_scence, &sc[6]);
	pthread_create(&th[7], NULL, &render_scence, &sc[7]);
	pthread_join(th[0], NULL);
	pthread_join(th[1], NULL);
	pthread_join(th[2], NULL);
	pthread_join(th[3], NULL);
	pthread_join(th[4], NULL);
	pthread_join(th[5], NULL);
	pthread_join(th[6], NULL);
	pthread_join(th[7], NULL);
	pthread_detach(th[0]);
	pthread_detach(th[1]);
	pthread_detach(th[2]);
	pthread_detach(th[3]);
	pthread_detach(th[4]);
	pthread_detach(th[5]);
	pthread_detach(th[6]);
	pthread_detach(th[7]);
	pthread_mutex_destroy(&data->mutex);
}
