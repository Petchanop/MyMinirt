/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subfunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:27:05 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/05 23:58:57 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while (str[i] < 33 && str[i] != '\0')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	return (convert_to_float(str, i, sign));
}
