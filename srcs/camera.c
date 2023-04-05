/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:50:06 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/04 17:26:01 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_cam	*init_camera( void )
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	cam->c = "C";
	cam->cpoint = (t_vector){0, 0, 0, 0};
	cam->vector = (t_vector){0, 0, 1, 0};
	cam->lookat = (t_vector){0, 0, 0, 0};
	cam->depth = 50;
	cam->fov = 70;
	cam->theta = degrees_to_radians(cam->fov);
	cam->len = 1;
	cam->aspect_ratio = (float)SCENCE_WIDTH / SCENCE_HEIGHT;
	cam->v_h = (t_vector){2 * cam->aspect_ratio, 0, 0, 0};
	cam->v_v = (t_vector){0, 2, 0, 0};
	cam->lower = find_lowerleft(cam->cpoint, cam->v_h, cam->v_v);
	return (cam);
}

float	degrees_to_radians(float degrees)
{
	return (degrees * M_PI / 180.0);
}

t_vector	find_lowerleft(t_vector cam, t_vector v_h, t_vector v_v)
{
	t_vector	lower;

	lower = vector_sub(cam, vector_div(v_h, 2));
	lower = vector_sub(lower, vector_div(v_v, 2));
	lower = vector_sub(lower, (t_vector){0, 0, 1, 0});
	return (lower);
}
//todo : calculate generate ray
/*lookfrom --> cpoint, origin*/