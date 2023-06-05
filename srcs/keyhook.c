/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:54:22 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/05 21:33:06 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	free_allobject(t_object *ob, t_cam *cam)
{
	int	i;

	i = 0;
	while (ob[i].type)
	{
		free(ob[i].type);
		i++;
	}
	free(ob);
	free(cam->c);
	free(cam->light.l);
	free(cam);
}

int	close_minirt(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->ob[i].type)
	{
		free(vars->ob[i].type);
		i++;
	}
	free(vars->ob);
	free(vars->cam->c);
	free(vars->cam->light.l);
	free(vars->cam);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	i;

	i = 0;
	(void)*vars;
	if (keycode == ON_ESCAPE)
	{
		while (vars->ob[i].type)
		{
			free(vars->ob[i].type);
			i++;
		}
		free(vars->ob);
		free(vars->cam->c);
		free(vars->cam->light.l);
		free(vars->cam);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}
