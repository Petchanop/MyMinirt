/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:20:15 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/02 19:17:24 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

t_object	*check_file(char *av, t_cam *cam, t_object *ob)
{
	int		fd;
	int		i;
	char	*line;
	char	**split_space;

	i = 0;
	fd = check_fd(av, cam, ob);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split_space = ft_split(line, ' ');
		if (!ft_strncmp(split_space[0], "A", 2))
			iden_a(cam, split_space);
		else if (!ft_strncmp(split_space[0], "C", 2))
			iden_c(cam, split_space);
		else if (!ft_strncmp(split_space[0], "L", 2))
			iden_l(cam, split_space);
		else if (!ft_strncmp(split_space[0], "pl", 3))
			iden_pl(&ob[i], split_space);
		else if (!ft_strncmp(split_space[0], "sp", 3))
			iden_sp(&ob[i], split_space);
		else if (!ft_strncmp(split_space[0], "cy", 3))
			iden_cy(&ob[i], split_space);
		else if (!ft_strncmp(split_space[0], "co", 3))
			iden_co(&ob[i], split_space);
		else if (!ft_strncmp(split_space[0], "#", 1))
			continue ;
		else if (!ft_strncmp(split_space[0], "\n", 1))
			continue ;
		else
			write_error ();
		if (ob[i].type)
		{
			i++;
			ob = reallocate_object(ob, cam, i);
		}
	}
	return (ob);
}

t_object	*reallocate_object(t_object *ob, t_cam *cam, int i)
{
	t_object	*new_ob;
	int			j;
	int			k;

	j = 0;
	k = 0;
	if (i == 0)
		return (ob);
	new_ob = malloc(sizeof(t_object) * (i + 1));
	while (i--)
	{
		new_ob[j] = ob[k];
		new_ob->cam = *cam;
		j++;
		k++;
	}
	new_ob[j].type = NULL;
	return (new_ob);
}
