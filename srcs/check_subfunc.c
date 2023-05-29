/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subfunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:27:05 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/30 00:49:08 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

int count(char **str)
{
    int i = 0;
    while (str[i] != NULL)
       i++;
    return (i);
}

int ft_isdigit(int n)
{
    if(n >= '0' && n <= '9')
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

float ft_atof (char *str)
{
    double result = 0.0;
    int sign = 1;
    int i = 0;
    int decimalflag = 0;
    double decimalmul = 1.0;
    while (str[i] < 33 && str[i] != '\0')
        i++;
	if(str[i] == '-')
	{
		sign = -1;
		i++;
	}
    while(str[i] >= '0' && str[i] <= '9' || str[i] == '.')
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

void write_error()
{
    write(2, "Error !!\n", 9);
    exit(1);
}