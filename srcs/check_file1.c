/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:20:15 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/31 02:07:44 by lkaewsae         ###   ########.fr       */
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
    t_cam *cam;
    cam = malloc(sizeof(t_cam));
        if (!cam)
            return (NULL);  
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        // int i = 0;
        //&cam->light
            //Each type of element can be separated by one or more line break(s).
            //Each type of information from an element can be separated by one or more space(s).
            //Each type of element can be set in any order in the file.
        if (ft_strncmp(split_space[0], "A", 2))//Ambient lightning identifier A, ratio 0-1, RGB color
            iden_a();
        else  if (ft_strncmp(split_space[0], "C", 2))// Cam identifier C, coor, vector, FOV
            iden_c();
        else if (ft_strncmp(split_space[0], "L", 2))//light identifier L, coor, ratio 0-1, RGB color 
            iden_l();
        else if (ft_strncmp(split_space[0], "pl", 3))//plane identifier pl, coor, vector, RGB color
            iden_pl();
        else if (ft_strncmp(split_space[0], "sp", 3))//Sphere identifier sp, coor, diameter, RGB color 
            iden_sp();
        else if (ft_strncmp(split_space[0], "cy", 3))//cylinder identifer cy, coor, vector, diameter, height, RGB color
            iden_cy();
        else if (ft_strncmp(split_space[0], "co", 3))
            iden_co();    
        else 
            write_error ();
    }
    return (ob);
}
        //Elements which are defined by a capital letter can only be declared once in the scene.
        //Each element first’s information is the type identifier (composed by one or two character(s)), 
        //followed by all specific information for each object in a strict order such as:
        
        //obj order
        

