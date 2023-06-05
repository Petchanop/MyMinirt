/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:30:21 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/05 23:50:14 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	check_size(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == '.')
		write_error("wrong size format ");
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			write_error("size is not a number ");
		else if (str[i] == '.')
		{
			count++;
			if (count > 1)
				write_error("size is not digit ");
		}
		i++;
	}
}

int	check_fov(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && ft_isdigit(str[i]) == 0)
			write_error("wrong Fov format ");
		i++;
	}
	if (check_range_fov(atoi(str)) == 0)
		write_error ("wrong fov format : fov not between 0 - 180 ");
	return (0);
}

void	is_vecinrange(char **split_vec)
{
	int	i;

	i = 0;
	while (split_vec[i] != NULL)
	{
		if (check_range_vec(atoi(split_vec[i])) == 0)
			write_error("vector value not between -1 - 1 ");
		i++;
	}
}

int	is_vec_valid(char **split_vec, int i, int vcount)
{
	int	j;

	j = 0;
	while (split_vec[i][j])
	{
		if ((!ft_isdigit(split_vec[i][0]) && split_vec[i][0] != '-')
			|| (split_vec[i][0] == '-' && split_vec[i][1] == '.'))
			write_error("wrong vector format : vector is not number ");
		else if (j != 0 && !ft_isdigit(split_vec[i][j])
			&& split_vec[i][j] != '.')
			write_error("wrong vector format : vector is not number ");
		else if (split_vec[i][j] == '.')
		{
			vcount++;
			if (vcount > 1)
				write_error ("wrong vector format ");
		}
		j++;
	}
	return (vcount);
}

void	check_vec(char *line)
{
	char	**split_vec;
	int		vcount;
	int		i;
	int		j;

	split_vec = ft_split(line, ',');
	i = 0;
	count_split(split_vec, 3, "Wrong vec format");
	is_vecinrange(split_vec);
	while (split_vec[i] != NULL)
	{
		vcount = 0;
		j = 0;
		is_vec_valid(split_vec, i, vcount);
		i++;
	}
	free2p(split_vec);
}
