/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:41:43 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/26 03:01:56 by lkaewsae         ###   ########.fr       */
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
    {
        write(2, "Error !!\n", 9);
        exit (EXIT_FAILURE);
    }
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
        // t_cam *cam;
        // cam = malloc(sizeof(t_cam))
        // if (!cam)
        //     return (NULL);  
            //Each type of element can be separated by one or more line break(s).
            //Each type of information from an element can be separated by one or more space(s).
            //Each type of element can be set in any order in the file.
            
        char **split_space;
        split_space = ft_split(line, ' ');
        
        if (ft_strncmp(ft_toupper(split_space[0])), "a", 2)//Ambient lightning identifier A, ratio 0-1, RGB color
        {
            if (count(split_space) != 3)
                exit (1);
            check_ratio(split_space[1]);
            check_RGB(split_space[2]);
            init_ambient(t_light *light)
        }
        else if (ft_strncmp(ft_toupper(split_space[0])), "c", 2)// Cam identifier C, coor, vector, FOV
        {
            if (count(split_space) != 4)
                exit (1);
            
        }
        else if (ft_strncmp(ft_toupper(split_space[0])), "l", 2)//light identifier L, coor, ratio 0-1, RGB color
        {
            if (count(split_space) != 4)
                exit (1);
        }
        else if (ft_strncmp(ft_toupper(split_space[0])), "pl", 3)//plane identifier pl, coor, vector, RGB color
        {
            if (count(split_space) != 4)
                exit (1);
        }
        else if (ft_strncmp(ft_toupper(split_space[0])), "sp", 3)//Sphere identifier sp, coor, diameter, RGB color 
        {
            if (count(split_space) != 4)
                exit (1);
        }
        else if (ft_strncmp(ft_toupper(split_space[0])), "cy", 3)//cylinder identifer cy, coor, vector, diameter, height, RGB color
        {
            if (count(split_space) != 5)
                exit (1);
        }
        else if (ft_strncmp(ft_toupper(split_space[0])), "co", 3)
        {
            if (count(split_space) != 5)
                exit (1);
        }
        else
            {
                write(2, "Error !!\n", 9);
                exit ;
            }
        //Elements which are defined by a capital letter can only be declared once in the scene.
        //Each element first’s information is the type identifier (composed by one or two character(s)), 
        //followed by all specific information for each object in a strict order such as:
        
        //obj order
    }
}

int check_ratio(char *str)
{
    int i = 0;
    if(str[i] == '0' || str[i] == '1')
    {
        i++;
        if (s[i] == '.' || s[i] == '\0')
        {
            while(str[i] != '\0')
            {
                if(!(s[i] >= '0' && s[i] <= '9'))
                {
                    return (0);
                }
            }
            return (1);
        } 
    }
    return (0);
}

int check_RGB(char *str)
{
    char **split_RGB = ft_split(line, ',');
    int i = 0;
    if (count(split_RGB) != 3) // if (funtion(split_RGB) != 3) strlen(char *)
        exit (1);
    while (split_RGB[i] != NULL)
    {
        int j = 0;
        while(split_RGB[i][j])
        {
            if (!ft_isdigit(split_RGB[i][j]))
            {
                write(2, "Error !!\n", 9);
                exit (1);
            }
            j++;
        }
        i++;  
    }
    i = 0;
    while (split_RGB[i] != NULL)
    {
        
        if (check_range(atoi(split_RGB[i])) == 0)
        {
            write(2, "Error !!\n", 9);
            exit (EXIT_FAILURE);
        }
        i++;
    }
    return (0);
}

int check_coor(char *str)
{
    char **split_coor = ft_split(line, ',');
    int i = 0;
    if (count(split_coor) != 3)
        exit (1);
    while (split_coor[i] != NULL)
    {
        int j = 0;
        int count = 0;
        while(split_coor[i][j])
        {
            if (!ft_isdigit(split_coor[i][0]) || split_coor[i][0] != '-' || (split_coor[i][0] == '-' && split_coor[i][1] == '.'))
            {
                write(2, "Error !!\n", 9);
                exit (1);
            }
            else if (!ft_isdigit(split_coor[i][j]) && split_coor[i][j] != '.')
            {
                write(2, "Error !!\n", 9);
                exit (1);
            }
            else if (split_coor[i][j] == '.')
            {
                count++;
                if (count > 1)
                {
                    write(2, "Error !!\n", 9);
                    exit (1);
                }
            }
            j++;
        }
        i++;  
    }
}
// free later