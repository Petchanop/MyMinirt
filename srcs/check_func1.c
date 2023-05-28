/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:41:43 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/28 20:45:54 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

char *line;
int check_ratio(char *str)
{
    int i = 0;
    //str[i] = ft_atoi(str[i]);
    if(str[i] == '0' || str[i] == '1')
    {
        i++;
        if (str[i] == '.' || str[i] == '\0')
        {
            while(str[i] != '\0')
            {
                if(!(str[i] >= '0' && str[i] <= '9'))
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
        
        if (check_range_RGB(atoi(split_RGB[i])) == 0)
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
    //char *line = "-1,2.0,0.12";
    char **split_coor = ft_split(line, ',');
    int i = 0;
    if (count(split_coor) != 3)
        exit (1);
   // char    *split_coor[] = {"-20.0", "-50.22", "10", NULL};
    while (split_coor[i] != NULL)
    {
        int j = 0;
        int count = 0;
        while(split_coor[i][j])
        {
            if (j == 0)
            {
                if ((!ft_isdigit(split_coor[i][0]) && split_coor[i][0] != '-') || (split_coor[i][0] == '-' && split_coor[i][1] == '.'))
                {
                    write(2, "Error1 !!\n", 10);
                    exit (1);
                }
            }
            else if (!ft_isdigit(split_coor[i][j]) && split_coor[i][j] != '.')
            {
                write(2, "Error2 !!\n", 10);
                exit (1);
            }
            else if (split_coor[i][j] == '.')
            {
                count++;
                if (count > 1)
                {
                    write(2, "Error3 !!\n", 10);
                    exit (1);
                }
            }
            j++;
        }
        i++;
    }  
}

int check_vec(char *str)
{
    //char *line = "-1,2.0,0.12";
    char **split_vec = ft_split(line, ',');
    int i = 0;
    if (count(split_vec) != 3)
        exit (1);
    while (split_vec[i] != NULL)
    {
        
        if (check_range_vec(atoi(split_vec[i])) == 0)
        {
            write(2, "Error !!\n", 9);
            exit (EXIT_FAILURE);
        }
        i++;
    }
    while (split_vec[i] != NULL)
    {
        int j = 0;
        int count = 0;
        while(split_vec[i][j])
        {
            if (!ft_isdigit(split_vec[i][0]) || split_vec[i][0] != '-' || (split_vec[i][0] == '-' && split_vec[i][1] == '.'))
            {
                write(2, "Error !!\n", 9);
                exit (1);
            }
            else if (!ft_isdigit(split_vec[i][j]) && split_vec[i][j] != '.')
            {
                write(2, "Error !!\n", 9);
                exit (1);
            }
            else if (split_vec[i][j] == '.')
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

int check_FOV(char *str)
{
    int i = 0;
    //char *str = "-180";
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0)
        {
            write(2, "Error !!\n", 9);
            exit (1);
        }
        i++;
    }
    if (check_range_FOV(atoi(str)) == 0)
    {
        write(2, "Error !!\n", 9);
        exit (1);
    }
    return (0);
}
// free later