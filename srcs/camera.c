/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:50:06 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/04 00:18:10 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	cameara_fov(t_cam *cam)
{
	cam->lookat = (t_vector){0, 0, -1, 0};
	t_vector w = vector_sub(cam->lookat, cam->cpoint);
	t_vector u = vector_normalize(cross_product(w, cam->vector));
	t_vector v = vector_normalize(cross_product(w, u));
	float	fl = ((float)SCENCE_WIDTH / (2 * cam->h));
	t_vector vp = vector_normalize(w);
	cam->v_h = u;
	cam->v_v = v;
	cam->lower.x = vp.x * fl - 0.5 * ((float)SCENCE_WIDTH * u.x + (float)SCENCE_HEIGHT * v.x);
	cam->lower.y = vp.y * fl - 0.5 * ((float)SCENCE_WIDTH * u.y + (float)SCENCE_HEIGHT * v.y);
	cam->lower.z = vp.z * fl - 0.5 * ((float)SCENCE_WIDTH * u.z + (float)SCENCE_HEIGHT * v.z);
	cam->lower.w = 0;
}

t_cam	*init_camera( void )
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	cam->c = "C";
	cam->cpoint = (t_vector){0, 1, -10, 0};
	cam->vector = (t_vector){0, 1, 0, 0};
	init_light(&cam->light);
	init_ambient(&cam->ambient);
	cam->aspect_ratio = (float)SCENCE_WIDTH / (float)SCENCE_HEIGHT;
	cam->t_max = T_MAX;
	cam->depth = 50;
	cam->fov = 156;
	// cam->fov = 90;
	cam->theta = degrees_to_radians(cam->fov * 0.5);
	cam->len = 1;
	cam->h = tan(cam->theta);
	
	// cameara_fov(cam);
	return (cam);
}

float	degrees_to_radians(float degrees)
{
	return (degrees * M_PI / 180.0);
}
//todo : calculate generate ray
/*lookfrom --> cpoint, origin*/