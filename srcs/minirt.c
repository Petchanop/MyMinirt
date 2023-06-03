/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:41:51 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/04 02:09:30 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//may pastel rgb = (t_color){255, 209, 220};

#include "../include/minirt.h"

void	build_image(t_data *img, int width, int length)
{
	img->bits_per_pixel = 32;
	img->line_length = width;
	img->endian = length;
	img->width = width;
	img->depth = length;
	img->zoom = 1.0;
}

void	init_t_data(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, SCENCE_WIDTH, SCENCE_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	if (!vars->angle)
	{
		vars->angle = 0;
		vars->angle1 = 0;
		vars->angle2 = 0;
	}
}

void	init_properties(t_object *ob, float radius, float height, float width)
{
	ob->radius = radius;
	ob->height = height;
	ob->width = width;
}

int	main(int argc, char **argv)
{
	t_cam		*cam;
	t_vars		vars;
	t_object	*ob;
	int			size;
	int			fd;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, SCENCE_WIDTH, SCENCE_HEIGHT, "npiya-is");
	build_image(&vars.img, 100, 100);
	init_t_data(&vars);
	if (argc != 2)
	{
		write(2, "Error !!", 9);
		exit (1);
	}
	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (1);
	fd = check_fd(argv[1], NULL, NULL);
	size = count_size(fd);
	ob = malloc(sizeof(t_object) * (size + 1));
	ob[size].type = NULL;
	ob[size].index = size;
	if (!ob)
		return (1);
	ob = check_file(argv[1], cam, ob);
	vars.ob = ob;
	vars.cam = cam;
	run_thread(cam, ob, &vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, ON_DESTROY, 1L << 0, close_minirt, &vars);
	mlx_loop(vars.mlx);
	pthread_mutex_destroy(&vars.mutex);
}
