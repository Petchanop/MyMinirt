/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:50:06 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/06 20:40:52 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_cam	*init_camera( void )
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	cam->c = "C";
	cam->cpoint = (t_vector){-2.0, 2.0, 1.0, 0};
	// cam->cpoint = (t_vector){0, 0, 0, 0};
	cam->lookat = (t_vector){0, 0, -1.0 , 0};
	// cam->lookat = (t_vector){0, 0, 0, 0};
	cam->vector = (t_vector){0, 1.0, 0, 0};
	// cam->vector = (t_vector){0, 0, 1, 0};
	cam->aspect_ratio = (float)SCENCE_WIDTH / (float)SCENCE_HEIGHT;
	cam->t_max = T_MAX;
	cam->depth = 50;
	cam->fov = 152.0 / cam->aspect_ratio;
	cam->theta = degrees_to_radians(cam->fov); 
	printf("theta : %f\n", cam->theta);
	cam->len = 1;
	cam->h = tan(cam->theta / 2);
	// cam->h = tan(cam->fov / 2);
	printf("h by fhov : %f\n", cam->h);
	t_vector w = vector_normalize(vector_sub(cam->cpoint, cam->lookat));
	t_vector u = vector_normalize(cross_product(cam->vector, w));
	t_vector v = cross_product(w, u);
	printf("w : %f, %f, %f\n", w.x, w.y, w.z);
	printf("u : %f, %f, %f\n", u.x, u.y, u.z);
	printf("v : %f, %f, %f\n", v.x, v.y, v.z);
	float	vp_h = 2 * cam->h;
	float	vp_w = cam->aspect_ratio * vp_h;
	// cam->v_h = (t_vector){vp_h, 0, 0, 0};
	// cam->v_v = (t_vector){0, vp_w, 0, 0};
	cam->v_h = vector_mul(u, vp_w);
	cam->v_v = vector_mul(v, vp_h);
	cam->lower = find_lowerleft(cam->cpoint, cam->v_h, cam->v_v, w);
	return (cam);
}

float	degrees_to_radians(float degrees)
{
	return (degrees * M_PI / 180.0);
}

t_vector	find_lowerleft(t_vector cam, t_vector v_h, t_vector v_v, t_vector w)
{
	t_vector	lower;

	lower = vector_sub(cam, vector_div(v_h, 2));
	lower = vector_sub(lower, vector_div(v_v, 2));
	lower = vector_add(lower, w);
	return (lower);
}
//todo : calculate generate ray
/*lookfrom --> cpoint, origin*/