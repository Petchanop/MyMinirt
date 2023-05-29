/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:30:21 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/30 00:51:41 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

void check_size(char *str)
{
    //char *str = "15.5";
	int i = 0;
	int count = 0;
	if (str[0] == '.')
		write_error();
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			write_error();
		else if (str[i] == '.')
		{
			count++;
			if (count > 1)
				write_error();
		}
		i++;
	}
}