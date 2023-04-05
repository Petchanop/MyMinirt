/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawSphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:52:11 by npiya-is          #+#    #+#             */
/*   Updated: 2023/03/31 18:52:31 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	hit_sphere(t_vector center, float radius, t_vector v, t_cam *cam)
{
	// t_hit	rec;
	//r.dir = v
	//at = orig + t* dir;
	t_vector	oc;

	oc = vector_sub(cam->cpoint, center);
	float	a = vector_length(v);
	float 	b = dot_product(oc, v);
	float	c = vector_length(oc) - (pow(radius, 2));
	float	dis = (b * b) - (a * c);
	if (dis < 0)
		return (-1);
	else
		return (0);
}


