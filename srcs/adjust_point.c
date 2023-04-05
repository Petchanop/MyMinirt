/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:40:04 by npiya-is          #+#    #+#             */
/*   Updated: 2023/03/24 13:44:56 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_point	rotatez(t_point pnt, t_vars vars)
{
	t_point	pre;

	pre = pnt;
	pnt.x = (pre.x * cos(vars.angle2)) + (pre.y * sin(vars.angle2));
	pnt.y = (pre.y * cos(vars.angle2)) - (pre.x * sin(vars.angle2));
	return (pnt);
}

t_point	rotatex(t_point pnt, t_vars vars)
{
	t_point	pre;

	pre = pnt;
	pnt.x = (pre.x * cos(vars.angle)) - (pre.z * sin(vars.angle));
	pnt.z = (pre.z * cos(vars.angle)) + (pre.x * sin(vars.angle));
	return (pnt);
}

t_point	rotatey(t_point pnt, t_vars vars)
{
	t_point	pre;

	pre = pnt;
	pnt.z = (pre.z * cos(vars.angle1)) - (pre.y * sin(vars.angle1));
	pnt.y = (pre.y * cos(vars.angle1)) + (pre.z * sin(vars.angle1));
	return (pnt);
}

t_point	translate_point(t_point pnt)
{
	pnt.x += 960;
	pnt.y += 540;
	pnt.z = 540 - pnt.z;
	return (pnt);
}

t_point	point_transformation(t_point pnt, t_vars vars)
{
	t_point	pre;

	pre = translate_point(pnt);
	pnt = rotatez(pre, vars);
	pnt = rotatex(pnt, vars);
	pnt = rotatey(pnt, vars);
	return (pnt);
}