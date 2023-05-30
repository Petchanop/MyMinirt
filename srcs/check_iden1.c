/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_iden1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:39:47 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/31 02:04:50 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

void    iden_a()
{
    char    **split_space;
    char    **line;
    int     acount;
    t_cam   *cam;
   
    split_space = ft_split(line, ' ');
    acount = 0;
        {
            
            acount++;
            if (count(split_space) != 3 || acount > 1)
                exit (1);
            check_ratio(split_space[1]);
            check_RGB(split_space[2]);
            cam->ambient.l = fr_strdup(split_space[0]);
            // /*convert split_space[1] to float (ratio)
            cam->ambient.bright_ratio = ft_atof(split_space[1]);
            // convert split_space[2] to t_color (see type.h)
            //255,255,255
            // 255 [0]
            // 255 [1]
            // 255 [2]
            char **colour;
            colour  = ft_split(split_space[2], ',');
            cam->ambient.color.r = ft_atof(colour[0]); 
            cam->ambient.color.g = ft_atof(colour[1]); 
            cam->ambient.color.b = ft_atof(colour[2]);
            free2p(colour);

            // pass it to function init_ambient
            // changes intit_ambient function parameter to
            // prototype init_ambient(t_light *light, float ratio, t_color color)*/
            // init_ambient(&cam->ambient, split_space[1], split_space[2]);
        }
}

void    iden_c()
{
    char    **split_space;
    char    **line;
    int     ccount;
    t_cam   *cam;
   
    split_space = ft_split(line, ' ');
    ccount = 0;
   
        {
            ccount++;
            if (count(split_space) != 4 || ccount > 1)
                exit (1);
            check_coor(split_space[1]);
            check_vec(split_space[2]);
            check_FOV(split_space[3]);
            //convert split_space[1] to t_vector assign to cam->cpoint
            // 1,2,3  ss[1]

            // x = 1
            // y = 2
            // z = 3
            cam->c = fr_strdup(split_space[0]);
            char **vector;
            vector = ft_split(split_space[1], ',');
            cam->cpoint.w = 0.0f;
            cam->cpoint.x = ft_atof(vector[0]);
            cam->cpoint.y = ft_atof(vector[1]);
            cam->cpoint.z = ft_atof(vector[2]);
            free2p(vector);
            // convert split_space[2] to t_vector assign to cam->vector
            vector = ft_split(split_space[2], ',');
            cam->vector.w = 0.0f;
            cam->vector.x = ft_atof(vector[0]);
            cam->vector.y = ft_atof(vector[1]);
            cam->vector.z = ft_atof(vector[2]);
            free2p(vector);
            //convert split_space[3] to float assign to cam->fov
            cam->fov = ft_atof(split_space[3]);
            //changes function parameter from void to intit_camare(t_vector coord, t_vector vector, float fov)
            
            // remove init_light and intit_ambient in init_camera*/
            //init_camera(void);
        }
}

void    iden_l()
{
    char    **split_space;
    char    **line;
    int     lcount;
    t_cam   *cam;
   
    split_space = ft_split(line, ' ');
    lcount = 0;
        {
            lcount++;
            if (count(split_space) != 4 || lcount > 1)
                exit (1);
            check_coor(split_space[1]);
            check_ratio(split_space[2]);
            check_RGB(split_space[3]);
            //do the same as init ambient light add one parameter coord
            cam->light.l = ft_strdup(split_space[0]);
            char **vector;
            vector = ft_split(split_space[1], ',');
            cam->light.point.x = 0.0f;
            cam->light.point.x = ft_atof(vector[0]);
            cam->light.point.y = ft_atof(vector[1]);
            cam->light.point.z = ft_atof(vector[2]);
            cam->light.bright_ratio = ft_atof(split_space[2]);
            char **colour;
            colour  = ft_split(split_space[3], ',');
            cam->light.color.b = ft_atof(colour[0]);
            cam->light.color.g = ft_atof(colour[1]);
            cam->light.color.r = ft_atof(colour[2]);
            
            //prototype init_light(t_light *light, t_vector coor, float ratio, t_color rgb)*/
            init_light(t_light *light);
        }
}