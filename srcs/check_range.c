/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:31:06 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/04 23:52:38 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	check_range_rgb(int n)
{
	if (n >= 0 && n <= 255)
		return (1);
	return (0);
}

int	check_range_vec(int n)
{
	if (n >= -1 && n <= 1)
		return (1);
	return (0);
}

int	check_range_fov(int n)
{
	if (n >= 0 && n <= 180)
		return (1);
	return (0);
}
