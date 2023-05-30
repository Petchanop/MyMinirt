/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:20:15 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/31 01:07:12 by lkaewsae         ###   ########.fr       */
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
        

