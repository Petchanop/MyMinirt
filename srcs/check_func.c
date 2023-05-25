/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:31:06 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/25 20:49:42 by lkaewsae         ###   ########.fr       */
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

int check_range(int n)
{
    if (n >= 0 && n <= 255)
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