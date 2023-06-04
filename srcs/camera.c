/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:50:06 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/04 15:30:51 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	cameara_fov(t_cam *cam)
{
	float		fl;
	float		x;
	float		y;
	float		z;
	t_vector	w;

	cam->lookat = (t_vector){0, 0, 0, 0};
	w = vector_sub(cam->lookat, cam->cpoint);
	w = vector_normalize(w);
	cam->u = vector_normalize(cross_product(w, cam->vector));
	cam->v = vector_normalize(cross_product(w, cam->u));
	fl = ((float)SC_WIDTH / (2 * cam->h));
	x = (float)SC_WIDTH * cam->u.x + (float)SC_HEIGHT * cam->v.x;
	y = (float)SC_WIDTH * cam->u.y + (float)SC_HEIGHT * cam->v.y;
	z = (float)SC_WIDTH * cam->u.z + (float)SC_HEIGHT * cam->v.z;
	cam->lower.x = w.x * fl - 0.5 * x;
	cam->lower.y = w.y * fl - 0.5 * y;
	cam->lower.z = w.z * fl - 0.5 * z;
	cam->lower.w = 0;
}

void	init_camera(t_cam *cam, t_vector c, t_vector v, float fov)
{
	cam->cpoint = c;
	cam->vector = v;
	cam->aspect_ratio = (float)SC_WIDTH / (float)SC_HEIGHT;
	cam->t_max = T_MAX;
	cam->depth = 50;
	cam->fov = fov;
	cam->theta = degrees_to_radians(cam->fov * 0.5);
	cam->h = tan(cam->theta);
	cameara_fov(cam);
}

float	degrees_to_radians(float degrees)
{
	return (degrees * M_PI / 180.0);
}
//todo : calculate generate ray
/*lookfrom --> cpoint, origin*/
