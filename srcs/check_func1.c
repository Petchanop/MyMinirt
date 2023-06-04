/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:41:43 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/04 20:01:54 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

int	check_ratio(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0' || str[i] == '1')
	{
		i++;
		if (str[i] == '.' || str[i] == '\0')
		{
			while (str[i] != '\0')
			{
				if (!(str[i] >= '0' && str[i] <= '9'))
					return (0);
			}
			return (1);
		}
	}
	return (0);
}

int	check_rgb(char *line)
{
	char	**split_rgb;
	int		i;
	int		j;

	split_rgb = ft_split(line, ',');
	i = 0;
	if (count(split_rgb) != 3)
		exit (1);
	while (split_rgb[i] != NULL)
	{
		j = 0;
		while (split_rgb[i][j] && split_rgb[i][j] != '\n')
		{
			if (!ft_isdigit(split_rgb[i][j]))
				write_error ("wrong RGB format : rgb is not digit ");
			j++;
		}
		i++;
	}
	i = 0;
	while (split_rgb[i] != NULL)
	{
		if (check_range_rgb(atoi(split_rgb[i])) == 0)
			write_error ("wrong RGB format : wrong range number ");
		i++;
	}
	free2p(split_rgb);
	return (0);
}

void	check_coor(char *line)
{
	char	**split_coor;
	int		ccount;
	int		i;
	int		j;

	i = 0;
	split_coor = ft_split(line, ',');
	if (count(split_coor) != 3)
		exit (1);
	while (split_coor[i] != NULL)
	{
		ccount = 0;
		j = 0;
		while (split_coor[i][j])
		{
			if (j == 0)
			{
				if ((!ft_isdigit(split_coor[i][0]) && split_coor[i][0] != '-')
					|| (split_coor[i][0] == '-' && split_coor[i][1] == '.'))
					write_error("wrong coordinates format : not number");
			}
			else if (!ft_isdigit(split_coor[i][j]) && split_coor[i][j] != '.')
				write_error("wrong coordinates format : not number");
			else if (split_coor[i][j] == '.')
			{
				ccount++;
				if (count > 1)
					write_error ("wrong coordinate format ");
			}
			j++;
		}
		i++;
	}
	free2p(split_coor);
}

void	check_vec(char *line)
{
	char	**split_vec;
	int		vcount;
	int		i;
	int		j;

	split_vec = ft_split(line, ',');
	i = 0;
	if (count(split_vec) != 3)
		exit (1);
	while (split_vec[i] != NULL)
	{
		if (check_range_vec(atoi(split_vec[i])) == 0)
			write_error("vector value not between -1 - 1 ");
		i++;
	}
	while (split_vec[i] != NULL)
	{
		vcount = 0;
		i = 0;
		j = 0;
		while (split_vec[i][j])
		{
			if (!ft_isdigit(split_vec[i][0]) || split_vec[i][0] != '-'
					|| (split_vec[i][0] == '-' && split_vec[i][1] == '.'))
				write_error("wrong vector format : vector is not number ");
			else if (!ft_isdigit(split_vec[i][j]) && split_vec[i][j] != '.')
				write_error("wrong vector format : vector is not number ");
			else if (split_vec[i][j] == '.')
			{
				vcount++;
				if (count > 1)
					write_error ("wrong vector format ");
			}
			j++;
		}
		i++;
	}
	free2p(split_vec);
}

int	check_fov(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && ft_isdigit(str[i]) == 0)
			write_error("wrong Fov formate ");
		i++;
	}
	if (check_range_fov(atoi(str)) == 0)
		write_error ("wrong fov format : fov not between 0 - 180 ");
	return (0);
}
