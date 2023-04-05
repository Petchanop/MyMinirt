/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:56:51 by npiya-is          #+#    #+#             */
/*   Updated: 2023/03/31 14:03:04 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

int color_cal(t_color col)
{
	int	result;

	result = col.b;
	result += col.g;
	result += col.r;
	return (result);
}

int main(void)
{
	t_color c = (t_color){0.00}
	printf("color : %d\n" color_cal());
}