/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_iden2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:11:38 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/31 02:07:37 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

void    iden_pl()
{
    char    **split_space;
    char    **line;
   
    split_space = ft_split(line, ' ');
    
        {
            if (count(split_space) != 4)
                exit (1);
            check_coor(split_space[1]);
            check_vec(split_space[2]);
            check_RGB(split_space[3]);
            //look at object.c file their are all prototype function
            // 1) init_properties (in minirt.c)
            init_properties(ob, radius, height, width);
            // 2) init by type (in object.c)
            init_type(ob, type, reflec);
            // 3) init_type (this function use for object texture)
            init_type();
            // function call look like this init_plane(ob, coor, vec, rgb)
            init_plane(ob, center, n, rgb);hy76
            // the rest of other shape do the same way*/
            //plane identifier
        }
}

void    iden_sp()
{
    char    **split_space;
    char    **line;
   
    split_space = ft_split(line, ' ');
    
        {
            if (count(split_space) != 4)
                exit (1);
            check_coor(split_space[1]);
            check_size(split_space[2]);
            check_RGB(split_space[3]);
            //Sphere identifier
        }
}

void    iden_cy()
{
    char    **split_space;
    char    **line;
   
    split_space = ft_split(line, ' ');
        {
            if (count(split_space) != 5)
                exit (1);
            check_coor(split_space[1]);
            check_vec(split_space[2]);
            check_size(split_space[3]);
            check_size(split_space[4]);
            check_RGB(split_space[5]);
            //cylinder identifer
        }
}

void    iden_co()
{
    char    **split_space;
    char    **line;
   
    split_space = ft_split(line, ' ');
    
        {
            if (count(split_space) != 5)
                exit (1);
            check_coor(split_space[1]);
            check_vec(split_space[2]);
            check_size(split_space[3]);
            check_size(split_space[4]);
            check_RGB(split_space[5]);
            //co identifer
        }
}