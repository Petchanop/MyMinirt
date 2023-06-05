/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subfunc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:55:56 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/05 23:58:13 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	convert_to_float(char *str, int i, int sign)
{
	int		decimalflag;
	double	decimalmul;
	double	result;

	decimalflag = 0;
	decimalmul = 1.0;
	result = 0.0;
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
