/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:41:43 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/05 23:52:56 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	count_split(char **split, int num, char *err)
{
	if (count(split) != num)
		write_error(err);
}

void	is_rgb_inrange(char **split_rgb)
{
	int	i;

	i = 0;
	while (split_rgb[i] != NULL)
	{
		if (check_range_rgb(atoi(split_rgb[i])) == 0)
			write_error ("RGB range must be between 0 - 255");
		i++;
	}
}

int	check_rgb(char *line)
{
	char	**split_rgb;
	int		i;
	int		j;

	split_rgb = ft_split(line, ',');
	i = 0;
	count_split(split_rgb, 3, "Wrong RGB format");
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
	is_rgb_inrange(split_rgb);
	free2p(split_rgb);
	return (0);
}

int	is_coord_valid(char **split_coor, int i, int j, int ccount)
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
		if (ccount > 1)
			write_error ("wrong coordinate format ");
	}
	return (ccount);
}

void	check_coor(char *line)
{
	char	**split_coor;
	int		ccount;
	int		i;
	int		j;

	i = 0;
	split_coor = ft_split(line, ',');
	count_split(split_coor, 3, "Wrong Coord format");
	while (split_coor[i] != NULL)
	{
		ccount = 0;
		j = 0;
		while (split_coor[i][j])
		{
			ccount = is_coord_valid(split_coor, i, j, ccount);
			j++;
		}
		i++;
	}
	free2p(split_coor);
}
