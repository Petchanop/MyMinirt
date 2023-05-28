/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:30:21 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/28 23:22:52 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

int check_size(char *str)
{
    //char *str = "15.5";
	int i = 0;
	int count = 0;
	if (str[0] == '.')
	{
		write(2, "Error !!\n", 9);
		exit (1);
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
		{
			write(2, "Error !!\n", 9);
			exit (1);
		}
		else if (str[i] == '.')
		{
			count++;
			if (count > 1)
			{
				write(2, "Error !!\n", 9);
				exit (1);
			}
		}
		i++;
	}
}