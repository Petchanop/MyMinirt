/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_iden2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:11:38 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/04 15:20:47 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	iden_pl(t_object *ob, char **split_space)
{
	char	**coor;
	char	**vec;
	char	**color;

	if (count(split_space) != 4)
		exit (1);
	check_coor(split_space[1]);
	check_vec(split_space[2]);
	check_RGB(split_space[3]);
	init_properties(ob, 0, 0, 0);
	init_type(ob, "df", "");
	coor = ft_split(split_space[1], ',');
	vec = ft_split(split_space[2], ',');
	color = ft_split(split_space[3], ',');
	ob->type = ft_strdup(split_space[0]);
	init_plane(ob, coor, vec, color);
	free2p(coor);
	free2p(vec);
	free2p(color);
}

void	iden_sp(t_object *ob, char **split_space)
{
	char	**coor;
	char	**size;
	char	**color;

	if (count(split_space) != 4)
		exit (1);
	check_coor(split_space[1]);
	check_size(split_space[2]);
	check_RGB(split_space[3]);
	coor = ft_split(split_space[1], ',');
	size = ft_split(split_space[2], ',');
	color = ft_split(split_space[3], ',');
	ob->type = ft_strdup(split_space[0]);
	init_properties(ob, ft_atof(size[0]) / 2, 0, 0);
	init_sphere(ob, coor, color);
	init_type(ob, "df", "");
	free2p(coor);
	free2p(size);
	free2p(color);
}

void	iden_cy(t_object *ob, char **split_space)
{
	char	**coor;
	char	**vec;
	char	**color;
	float	length;
	float	dia;

	if (count(split_space) != 6)
		exit (1);
	check_coor(split_space[1]);
	check_vec(split_space[2]);
	check_size(split_space[3]);
	check_size(split_space[4]);
	check_RGB(split_space[5]);
	coor = ft_split(split_space[1], ',');
	vec = ft_split(split_space[2], ',');
	color = ft_split(split_space[5], ',');
	dia = ft_atof(split_space[3]) / 2;
	length = ft_atof(split_space[4]);
	ob->type = ft_strdup(split_space[0]);
	init_properties(ob, dia, length, 0);
	init_cylinder(ob, coor, vec, color);
	init_type(ob, "df", "");
	free2p(coor);
	free2p(vec);
	free2p(color);
}

void	iden_co(t_object *ob, char **split_space)
{
	char	**coor;
	char	**vec;
	char	**color;
	float	length;
	float	dia;

	if (count(split_space) != 6)
		exit (1);
	check_coor(split_space[1]);
	check_vec(split_space[2]);
	check_size(split_space[3]);
	check_size(split_space[4]);
	check_RGB(split_space[5]);
	coor = ft_split(split_space[1], ',');
	vec = ft_split(split_space[2], ',');
	color = ft_split(split_space[5], ',');
	dia = ft_atof(split_space[3]) / 2;
	length = ft_atof(split_space[4]);
	ob->type = ft_strdup(split_space[0]);
	init_properties(ob, dia, length, 0);
	init_cone(ob, coor, vec, color);
	init_type(ob, "df", "");
	free2p(coor);
	free2p(vec);
	free2p(color);
}
