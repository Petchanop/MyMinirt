/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:30:21 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/03 23:40:37 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


void check_size(char *str)
{
	int i = 0;
	int count = 0;
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
