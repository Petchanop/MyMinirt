/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_iden2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:11:38 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/31 20:33:22 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

void    iden_pl(t_object *ob, char **split_space)
{
    // char    **split_space;
    // char    **line;
    char	**coor;
	char	**vec;
	char	**color;
    
   
    // split_space = ft_split(line, ' ');
    if (count(split_space) != 4)
        exit (1);
    check_coor(split_space[1]);
    check_vec(split_space[2]);
    check_RGB(split_space[3]);
    //look at object.c file their are all prototype function
    // 1) init_properties (in minirt.c)
    init_properties(ob, 0, 0, 0);
    // 2) init by type (in object.c)
    init_type(ob, "pl", "");
    // 3) init_type (this function use for object texture)
   // init_type();
    // function call look like this init_plane(ob, coor, vec, rgb)
    coor = ft_split(split_space[1], ',');
	vec = ft_split(split_space[2], ',');
	color = ft_split(split_space[3], ',');
	init_plane(ob, coor, vec, color);
    // the rest of other shape do the same way*/
    //plane identifier
}

void    iden_sp(t_object *ob, char **split_space)
{
    char    **split_space;
    char    **line;
	char	**coor;
	char	**size;
	char	**color;
   
    //split_space = ft_split(line, ' ');
    if (count(split_space) != 4)
        exit (1);
    check_coor(split_space[1]);
    check_size(split_space[2]);
    check_RGB(split_space[3]);
	coor = ft_split(split_space[1], ',');
	size = ft_split(split_space[2], ',');
	color = ft_split(split_space[3], ',');
	init_sphere(ob, coor, size, color);
    //Sphere identifier
}

void    iden_cy(t_object *ob, char **split_space)
{
	char	**coor;
	char	**vec;
	char	**color;
	char	**length;
	char	**dia;
	
	
   
    //split_space = ft_split(line, ' ');
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
    //cylinder identifer
}

void    iden_co(t_object *ob, char **split_space)
{
	char	**coor;
	char	**vec;
	char	**color;
	char	**length;
	char	**dia;
   
    //split_space = ft_split(line, ' ');
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
    //co identifer
}