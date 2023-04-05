/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:51:48 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/02 00:52:47 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"

typedef struct s_ray
{
	t_vector	origin;
	t_vector	dir;
	float		t;
}	t_ray;

typedef struct s_cam
{
	char		*c;
	t_vector	cpoint;
	t_vector	vector;
	t_vector	lower;
	t_vector	v_h;
	t_vector	v_v;
	t_vector	v_w;
	t_vector	lookat;
	float		theta;
	float		depth;
	float		h;
	float		len;
	float		focus_dist;
	float		aspect_ratio;
	float		fov;
}	t_cam;

t_cam		*init_camera( void );
float		degrees_to_radians(float degrees);
t_vector	find_lowerleft(t_vector cam, t_vector v_h, t_vector v_v);

#endif