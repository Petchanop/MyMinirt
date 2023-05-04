/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:50:06 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 01:43:46 by npiya-is         ###   ########.fr       */
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

	cam->lookat = (t_vector){1, 0, 0, 0};
	w = vector_sub(cam->lookat, cam->cpoint);
	w = vector_normalize(w);
	cam->u = vector_normalize(cross_product(w, cam->vector));
	cam->v = vector_normalize(cross_product(w, cam->u));
	fl = ((float)SCENCE_WIDTH / (2 * cam->h));
	x = (float)SCENCE_WIDTH * cam->u.x + (float)SCENCE_HEIGHT * cam->v.x;
	y = (float)SCENCE_WIDTH * cam->u.y + (float)SCENCE_HEIGHT * cam->v.y;
	z = (float)SCENCE_WIDTH * cam->u.z + (float)SCENCE_HEIGHT * cam->v.z;
	cam->lower.x = w.x * fl - 0.5 * x;
	cam->lower.y = w.y * fl - 0.5 * y;
	cam->lower.z = w.z * fl - 0.5 * z;
	cam->lower.w = 0;
}

t_cam	*init_camera( void )
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	cam->c = "C";
	cam->cpoint = (t_vector){0, 6, -10, 0};
	cam->vector = (t_vector){0, 1, 0, 0};
	init_light(&cam->light);
	init_ambient(&cam->ambient);
	cam->aspect_ratio = (float)SCENCE_WIDTH / (float)SCENCE_HEIGHT;
	cam->t_max = T_MAX;
	cam->depth = 50;
	cam->fov = 90;
	cam->theta = degrees_to_radians(cam->fov * 0.5);
	cam->len = 1;
	cam->h = tan(cam->theta);
	cameara_fov(cam);
	return (cam);
}

float	degrees_to_radians(float degrees)
{
	return (degrees * M_PI / 180.0);
}
//todo : calculate generate ray
/*lookfrom --> cpoint, origin*/