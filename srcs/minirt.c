/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:41:51 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/19 01:05:42 by npiya-is         ###   ########.fr       */
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
	(void)argc;
	(void)argv;

	t_cam		*cam;
	t_vars		vars;
	t_object	*ob;
	t_vector	p;
	t_vector	n;
	t_color 	rgb;
	t_color 	rgb1;
	t_color 	rgb2;
	t_color 	rgb3;
	t_color 	rgb4;
	t_color 	rgb5;
	t_color 	rgb6;

	ob = malloc(sizeof(t_object) * 8);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, SCENCE_WIDTH, SCENCE_HEIGHT, "npiya-is");
	build_image(&vars.img, 100, 100);
	init_t_data(&vars);
	cam = init_camera();
	p = (t_vector){0, 0, -1, 0};
	t_vector p1 = (t_vector){1, 0, -1, 0};
	t_vector p2 = (t_vector){-1, 0, -1, 0};
	t_vector p3 = (t_vector){-1.5, 1, 1, 0};
	t_vector p4 = (t_vector){2, 1, 0, 0};
	// t_vector p5 = (t_vector){0, 0, 1, 0};
	n = (t_vector){0, -100.5, -1, 0};
	rgb = (t_color){25.0 / 255.999, 50.0 / 255.999, 125.0 / 255.999};
	rgb1 = (t_color){240.0 / 255.999, 150.0 / 255.999, 100.0 / 255.999};
	rgb2 = (t_color){150.0 / 255.999, 150.0 / 255.999, 100.0 / 255.999};
	rgb3 = (t_color){0.85, 0.85, 0.0};
	rgb4 = (t_color){170.0 / 255.999, 80.0 / 255.999, 40.0 / 255.999};
	rgb5 = (t_color){50.0 / 255.999, 200.0 / 255.999, 240.0 / 255.999};
	rgb6 = (t_color){179.0 / 255.999, 140.0 / 255.999, 60.0 / 255.999};
	init_object(&ob[0], p, (t_vector){0, 0, 1, 0}, rgb);
	init_object(&ob[1], p1, (t_vector){0, 0, 1, 0}, rgb1);
	init_object(&ob[2], n, (t_vector){0, 0, 1, 0}, rgb3);
	init_object(&ob[3], p2, (t_vector){0, 0, 1, 0}, rgb2);
	init_object(&ob[4], p3, (t_vector){0, 0, 1, 0}, rgb4);
	init_object(&ob[5], p4, (t_vector){0, 0, 1, 0}, rgb5);
	// init_object(&ob[6], p5, (t_vector){0, 0, 1, 0}, rgb6);
	init_type(&ob[0], "df", "1");
	init_type(&ob[1], "df", "gl");
	init_type(&ob[2], "df", "2");
	init_type(&ob[3], "df", "");
	init_type(&ob[4], "df", "3");
	init_type(&ob[5], "mt", "gl");
	// init_type(&ob[6], "df", "");
	ob[6].type = NULL;
	init_properties(&ob[0], 0.5, 0, 0);
	init_properties(&ob[1], 0.5, 0, 0);
	init_properties(&ob[2], 100, 0, 0);
	init_properties(&ob[3], 0.5, 0, 0);
	init_properties(&ob[4], 0.5, 0, 0);
	init_properties(&ob[5], 0.5, 0, 0);
	// init_properties(&ob[6], 1.5, 0, 0);
	rgb = (t_color){0, 0, 0};
	ob[0].index = 0;
	ob[1].index = 1;
	ob[2].index = 2;
	ob[3].index = 3;
	ob[4].index = 4;
	ob[5].index = 5;
	ob[6].index = 6;
	create_background(cam, ob, &vars.img, rgb);
	// draw_sphere(ob, vars, cam);
	/*define which camera angle for object*/
	/*find where light source is and how effect color*/
	/*render shadow and Phoung shading*/

	/*1st try with simple sphere shape*/
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
	free(cam);
	free(ob);
}
