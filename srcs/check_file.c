/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:20:15 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/30 13:09:13 by npiya-is         ###   ########.fr       */
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
            /*convert split_space[1] to float (ratio)
            convert split_space[2] to t_color (see type.h)
            pass it to function init_ambient
            changes intit_ambient function parameter to
            prototype init_ambient(t_light *light, float ratio, t_color color)*/
            // init_ambient(&cam->ambient, ratio, color);
        }
        else if (ft_strncmp(split_space[0], "C", 2))// Cam identifier C, coor, vector, FOV
        {
            ccount++;
            if (count(split_space) != 4 || ccount > 1)
                exit (1);
            check_coor(split_space[1]);
            check_vec(split_space[2]);
            check_FOV(split_space[3]);
            /*convert split_space[1] to t_vector assign to cam->cpoint 
            convert split_space[2] to t_vector assign to cam->vector
            convert split_space[3] to float assign to cam->fov
            changes function parameter from void to intit_camare(t_vector coord, t_vector vector, float fov)
            remove init_light and intit_ambient in init_camera*/
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
            /*do the same as init ambient light add one parameter coord
            prototype init_light(t_light *light, t_vector coor, float ratio, t_color rgb)*/
            //init_light(t_light *light);
        }
        else if (ft_strncmp(split_space[0], "pl", 3))//plane identifier pl, coor, vector, RGB color
        {
            if (count(split_space) != 4)
                exit (1);
            check_coor(split_space[1]);
            check_vec(split_space[2]);
            check_RGB(split_space[3]);
            /*look at object.c file their are all prototype function
            1) init_properties (in minirt.c)
            2) init by type (in object.c)
            3) init_type (this function use for object texture)
            function call look like this init_plane(ob, coor, vec, rgb)
            the rest of other shape do the same way*/
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
        //check upper

