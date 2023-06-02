/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:41:43 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/02 18:51:28 by npiya-is         ###   ########.fr       */
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
	//str[i] = ft_atoi(str[i]);
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

int	check_RGB(char *line)
{
	char	**split_RGB;
	int		i;

	split_RGB = ft_split(line, ',');
	i = 0;
	if (count(split_RGB) != 3)
		exit (1);
	while (split_RGB[i] != NULL)
	{
		int j = 0;
		while (split_RGB[i][j] && split_RGB[i][j] != '\n')
		{
			if (!ft_isdigit(split_RGB[i][j]))
				write_error ();
			j++;
		}
		i++;
	}
	i = 0;
	while (split_RGB[i] != NULL)
	{

		if (check_range_RGB(atoi(split_RGB[i])) == 0)
			write_error ();
		i++;
	}
	free2p(split_RGB);
	return (0);
}

void	check_coor(char *line)
{
	char	**split_coor;
	int		i;

	i = 0;
	split_coor = ft_split(line, ',');
	if (count(split_coor) != 3)
		exit (1);
	while (split_coor[i] != NULL)
	{
		int j = 0;
		int count = 0;
		while (split_coor[i][j])
		{
			if (j == 0)
			{
				if ((!ft_isdigit(split_coor[i][0]) && split_coor[i][0] != '-') || (split_coor[i][0] == '-' && split_coor[i][1] == '.'))
					write_error();
			}
			else if (!ft_isdigit(split_coor[i][j]) && split_coor[i][j] != '.')
				write_error();
			else if (split_coor[i][j] == '.')
			{
				count++;
				if (count > 1)
					write_error ();
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
	int		i;

	split_vec = ft_split(line, ',');
	i = 0;
	if (count(split_vec) != 3)
		exit (1);
	while (split_vec[i] != NULL)
	{

		if (check_range_vec(atoi(split_vec[i])) == 0)
			write_error();
		i++;
	}
	while (split_vec[i] != NULL)
	{
		int j;
		int count;

		i = 0;
		count = 0;
		j = 0;
		while (split_vec[i][j])
		{
			if (!ft_isdigit(split_vec[i][0]) || split_vec[i][0] != '-' || (split_vec[i][0] == '-' && split_vec[i][1] == '.'))
				write_error();
			else if (!ft_isdigit(split_vec[i][j]) && split_vec[i][j] != '.')
				write_error();
			else if (split_vec[i][j] == '.')
			{
				count++;
				if (count > 1)
					write_error ();
			}
			j++;
		}
		i++;
	}
	free2p(split_vec);
}

int	check_FOV(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && ft_isdigit(str[i]) == 0)
			write_error();
		i++;
	}
	if (check_range_FOV(atoi(str)) == 0)
		write_error ();
	return (0);
}
