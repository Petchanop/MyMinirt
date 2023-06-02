/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_iden2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:11:38 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/02 23:01:21 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

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
	printf("%s coord: %f, %f, %f\n", ob->type, ob->center.x, ob->center.y, ob->center.z);
	printf("color: %f %f %f, width : %f\n" ,ob->color.r, ob->color.g, ob->color.b, ob->radius);
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
	printf("%s coord: %f, %f, %f\n", ob->type, ob->center.x, ob->center.y, ob->center.z);
	printf("color: %f %f %f, width : %f\n" ,ob->color.r, ob->color.g, ob->color.b, ob->radius);
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
	printf("%s coord: %f, %f, %f\n", ob->type, ob->center.x, ob->center.y, ob->center.z);
	printf("color: %f %f %f, width : %f\n" ,ob->color.r, ob->color.g, ob->color.b, ob->radius);
}

void	iden_co(t_object *ob, char **split_space)
{
	char	**coor;
	char	**vec;
	char	**color;
	float	length;
	float	dia;

	if (count(split_space) != 5)
		exit (1);
	check_coor(split_space[1]);
	check_vec(split_space[2]);
	check_size(split_space[3]);
	check_size(split_space[4]);
	check_RGB(split_space[5]);
	coor = ft_split(split_space[1], ',');
	vec = ft_split(split_space[2], ',');
	color = ft_split(split_space[3], ',');
	dia = ft_atof(split_space[3]) / 2;
	length = ft_atof(split_space[4]);
	ob->type = ft_strdup(split_space[0]);
	init_properties(ob, dia, length, 0);
	init_cone(ob, coor, vec, color);
	init_type(ob, "df", "");
}
