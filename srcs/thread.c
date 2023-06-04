/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:16:49 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/04 15:30:51 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_scene(t_scene sc[], t_cam *cam, t_object *ob, t_vars *data)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (ob[count].type)
		count++;
	count++;
	while (i < THREAD_NUM)
	{
		sc[i].ob = malloc(sizeof(t_object) * count);
		sc[i].id = i + 1;
		sc[i].c = *cam;
		sc[i].data = data;
		j = 0;
		while (ob[j].type)
		{
			sc[i].ob[j] = ob[j];
			j++;
		}
		sc[i].ob[j].type = NULL;
		i++;
	}
}

void	assign_section(t_scene *sc, int x[], int y[])
{
	sc->maxx = x[0];
	sc->maxy = y[0] / 2;
	sc->minx = x[1];
	sc->miny = y[1];
}

void	assign_portion(t_scene sc[])
{
	int			i;
	int			sizex[2];
	int			sizey[2];
	int			dx;

	i = 0;
	dx = (SC_WIDTH) / 5;
	sizey[0] = SC_HEIGHT - 1;
	sizey[1] = 0;
	sizex[0] = dx;
	sizex[1] = 0;
	while (i < THREAD_NUM)
	{
		assign_section(&sc[i], sizex, sizey);
		sizex[1] += dx;
		sizex[0] += dx;
		if (i == 4)
		{
			sizey[1] += sizey[0] / 2;
			sizey[0] *= 2;
			sizex[1] = 0;
			sizex[0] = dx;
		}
		i++;
	}
}

void	run_thread(t_cam *cam, t_object *ob, t_vars *data)
{
	pthread_t	th[10];
	t_scene		sc[10];
	int			i;

	i = 0;
	init_scene(sc, cam, ob, data);
	pthread_mutex_init(&data->mutex, NULL);
	assign_portion(sc);
	while (i < THREAD_NUM)
	{
		if (pthread_create(&th[i], NULL, &render_scene, &sc[i]) != 0)
			printf("Thread %d fail to create\n", i + 1);
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
		pthread_join(th[i++], NULL);
	i = 0;
	while (i < THREAD_NUM)
		pthread_detach(th[i++]);
	free_scene(sc);
}

void	free_scene(t_scene sc[])
{
	int	i;

	i = 0;
	while (i < THREAD_NUM)
		free(sc[i++].ob);
}
