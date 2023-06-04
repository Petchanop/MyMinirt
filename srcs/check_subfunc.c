/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subfunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:27:05 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/04 20:33:34 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

int	count(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int	file_extension(char *av)
{
	if (ft_strrchr(av, '.') == NULL)
		return (0);
	if (!ft_strncmp(ft_strrchr(av, '.'), ".rt", 4))
		return (0);
	return (1);
}

void	free2p(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		free (ptr[i++]);
	free (ptr);
}

float	ft_atof(char *str)
{
	double	result;
	int		sign;
	int		i;
	int		decimalflag;
	double	decimalmul;

	result = 0.0;
	sign = 1;
	i = 0;
	decimalflag = 0;
	decimalmul = 1.0;
	while (str[i] < 33 && str[i] != '\0')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] == '.')
			decimalflag = 1;
		else if (decimalflag == 0)
			result = result * 10 + (str[i] - '0');
		else
		{
			decimalmul *= 0.1;
			result = result + (str[i] - '0') * decimalmul;
		}
		i++;
	}
	return ((float)(sign * result));
}
