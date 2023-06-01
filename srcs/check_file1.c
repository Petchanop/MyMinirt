/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:20:15 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/31 21:22:20 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

t_object *check_file(char *av, t_cam *cam, t_object *ob)
{
    int     fd;
    int     acount;
    char    *line;
    char    **split_space;

    fd = check_fd(av, cam, ob);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        split_space = ft_split(line, ' ');
        if (ft_strncmp(split_space[0], "A", 2))
            iden_a(cam, split_space, acount);
        else  if (ft_strncmp(split_space[0], "C", 2))
            iden_c(cam, split_space, acount);
        else if (ft_strncmp(split_space[0], "L", 2))
            iden_l(cam, split_space);
        else if (ft_strncmp(split_space[0], "pl", 3))
            iden_pl(ob, split_space);
        else if (ft_strncmp(split_space[0], "sp", 3))
            iden_sp(ob, split_space);
        else if (ft_strncmp(split_space[0], "cy", 3))
            iden_cy(ob, split_space);
        else if (ft_strncmp(split_space[0], "co", 3))
            iden_co(ob, split_space);    
        else 
            write_error ();
    }
    return (ob);
}
        //Elements which are defined by a capital letter can only be declared once in the scene.
        //Each element first’s information is the type identifier (composed by one or two character(s)), 
        //followed by all specific information for each object in a strict order such as:
        
        //obj order
        
t_object   *reallocate_object(t_object *ob, int i)
{
    t_object    *new_ob;
    int         j;
    int         k;

    j = 0;
    k = 0;
    new_ob = malloc(sizeof(t_object) * (i + 1));
    while (i)
    {
        new_ob[j] = ob[k];
        j++;
        k++;
        i--;
    }
    new_ob[j].type = NULL;
    return (new_ob);
}
