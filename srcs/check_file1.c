/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:20:15 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/04 02:06:49 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	assign_env(t_cam *cam, char **split_space)
{
	if (!ft_strncmp(split_space[0], "A", 2))
		return (iden_a(cam, split_space));
	else if (!ft_strncmp(split_space[0], "C", 2))
		return (iden_c(cam, split_space));
	else if (!ft_strncmp(split_space[0], "L", 2))
		return (iden_l(cam, split_space));
	return (0);
}

int	assign_object(t_object *ob, char **split_space, int i)
{
	if (ft_strncmp(split_space[0], "A", 2) && ft_strncmp(split_space[0], "C", 2)
		&& ft_strncmp(split_space[0], "L", 2))
	{
		if (!ft_strncmp(split_space[0], "pl", 3))
		{
			iden_pl(&ob[i], split_space);
			ob[i].index = i;
			i++;
		}
		else if (!ft_strncmp(split_space[0], "sp", 3))
		{
			iden_sp(&ob[i], split_space);
			ob[i].index = i;
			i++;
		}
		else if (!ft_strncmp(split_space[0], "cy", 3))
		{
			iden_cy(&ob[i], split_space);
			ob[i].index = i;
			i++;
		}
		else if (!ft_strncmp(split_space[0], "co", 3))
		{
			iden_co(&ob[i], split_space);
			ob[i].index = i;
			i++;
		}
	}
	else if (ft_strncmp(split_space[0], "#", 1) && ft_strncmp(split_space[0], "\n", 1))
		write_error ("type not match in program format ");
	return (i);
}

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
		free(line);
		if (!assign_env(cam, split_space))
			i = assign_object(ob, split_space, i);
		free2p(split_space);
	}
	return (ob);
}

int	count_size(int fd)
{
	int		size;
	char	*line;
	char	**split_space;

	size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split_space = ft_split(line, ' ');
		free(line);
		if (!ft_strncmp(split_space[0], "pl", 3))
			size++;
		else if (!ft_strncmp(split_space[0], "sp", 3))
			size++;
		else if (!ft_strncmp(split_space[0], "cy", 3))
			size++;
		else if (!ft_strncmp(split_space[0], "co", 3))
			size++;
		free2p(split_space);
	}
	close(fd);
	return (size);
}
