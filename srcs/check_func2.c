/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:30:21 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/04 20:07:55 by lkaewsae         ###   ########.fr       */
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
