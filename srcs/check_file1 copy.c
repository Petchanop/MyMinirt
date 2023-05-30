/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file1 copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:20:15 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/31 00:50:52 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

t_object *check_file(char *av)
{
    int fd;
    char *line;
    
    if(file_extension(av))
        write_error();
    fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror(av);
		exit(EXIT_FAILURE);
	}
    t_object *ob = NULL;
    ob = malloc (sizeof(t_object));
    if (!ob)
        return (NULL);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        // int i = 0;
        t_cam *cam;
        //&cam->light
        cam = malloc(sizeof(t_cam));
        if (!cam)
            return (NULL);  
            //Each type of element can be separated by one or more line break(s).
            //Each type of information from an element can be separated by one or more space(s).
            //Each type of element can be set in any order in the file.
            
        char **split_space;
        split_space = ft_split(line, ' ');
        int acount = 0;
        int ccount = 0;
        int lcount = 0;
        if (ft_strncmp(split_space[0], "A", 2))//Ambient lightning identifier A, ratio 0-1, RGB color
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
        else if (ft_strncmp(split_space[0], "C", 2))// Cam identifier C, coor, vector, FOV
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
        else if (ft_strncmp(split_space[0], "L", 2))//light identifier L, coor, ratio 0-1, RGB color
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
        else if (ft_strncmp(split_space[0], "pl", 3))//plane identifier pl, coor, vector, RGB color
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
        else if (ft_strncmp(split_space[0], "sp", 3))//Sphere identifier sp, coor, diameter, RGB color 
        {
            if (count(split_space) != 4)
                exit (1);
            check_coor(split_space[1]);
            check_size(split_space[2]);
            check_RGB(split_space[3]);
            //Sphere identifier
        }
        else if (ft_strncmp(split_space[0], "cy", 3))//cylinder identifer cy, coor, vector, diameter, height, RGB color
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
        else if (ft_strncmp(split_space[0], "co", 3))
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
        else
            {
                write(2, "Error !!\n", 9);
                exit (1);
            }
    }
    return (ob);
}
        //Elements which are defined by a capital letter can only be declared once in the scene.
        //Each element first’s information is the type identifier (composed by one or two character(s)), 
        //followed by all specific information for each object in a strict order such as:
        
        //obj order
        

