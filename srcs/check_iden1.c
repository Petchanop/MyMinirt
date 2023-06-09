/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_iden1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:39:47 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/05 23:10:21 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	iden_a(t_cam *cam, char **split_space)
{
	t_color				color;
	char				**colour;

	if (count(split_space) != 3)
		write_error("Wrong object format");
	check_ratio(split_space[1]);
	check_rgb(split_space[2]);
	colour = ft_split(split_space[2], ',');
	color.r = ft_atof(colour[0]) / 255.999;
	color.g = ft_atof(colour[1]) / 255.999;
	color.b = ft_atof(colour[2]) / 255.999;
	init_ambient(&cam->ambient, ft_atof(split_space[1]), color);
	free2p(colour);
	return (1);
}

int	iden_c(t_cam *cam, char **split_space)
{
	char				**coord;
	char				**vec;
	t_vector			c;
	t_vector			v;

	if (count(split_space) != 4)
		write_error("Wrong object format");
	check_coor(split_space[1]);
	check_vec(split_space[2]);
	check_fov(split_space[3]);
	cam->c = ft_strdup(split_space[0]);
	coord = ft_split(split_space[1], ',');
	c = (t_vector){ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]), 0};
	vec = ft_split(split_space[2], ',');
	v = (t_vector){ft_atof(vec[0]), ft_atof(vec[1]), ft_atof(vec[2]), 0};
	init_camera(cam, c, v, ft_atof(split_space[3]));
	free2p(coord);
	free2p(vec);
	return (1);
}

int	iden_l(t_cam *cam, char **split_space)
{
	char				**vec;
	char				**col;
	t_vector			c;
	t_color				color;

	if (count(split_space) != 4)
		write_error("Wrong object format");
	check_coor(split_space[1]);
	check_ratio(split_space[2]);
	check_rgb(split_space[3]);
	cam->light.l = ft_strdup(split_space[0]);
	vec = ft_split(split_space[1], ',');
	col = ft_split(split_space[3], ',');
	c = (t_vector){ft_atof(vec[0]), ft_atof(vec[1]), ft_atof(vec[2]), 0};
	color = (t_color){ft_atof(col[0]), ft_atof(col[1]), ft_atof(col[2])};
	init_light(&cam->light, c, color, ft_atof(split_space[2]));
	free2p(vec);
	free2p(col);
	return (1);
}
