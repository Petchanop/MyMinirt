/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finddxdy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:14:09 by npiya-is          #+#    #+#             */
/*   Updated: 2023/03/22 15:14:26 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_point	find_dxdy(t_point start, t_point end)
{
	t_point		diff;

	diff.x = (end.x - start.x);
	diff.y = (end.y - start.y);
	diff.z = (end.z - start.z);
	return (diff);
}

float	find_stepxy(t_point diff)
{
	if (fabs(diff.x) >= fabs(diff.y))
		return (fabs(diff.x));
	else
		return (fabs(diff.y));
}

float	find_stepxz(t_point diff)
{
	if (fabs(diff.x) >= fabs(diff.z))
		return (fabs(diff.x));
	else
		return (fabs(diff.z));
}