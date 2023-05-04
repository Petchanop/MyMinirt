/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:48:40 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/04 15:57:10 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef struct s_matrix
{
	float	m[4][4];
}	t_matrix;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vector;

typedef struct s_light
{
	char		*l;
	float		bright_ratio;
	t_vector	point;
	t_vector	vector;
	t_vector	dir;
	t_color		color;
}	t_light;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	dir;
	t_vector	normal;
	float		t;
}	t_ray;

typedef struct s_cam
{
	char		*c;
	t_vector	cpoint;
	t_vector	vector;
	t_vector	lookat;
	t_vector	v_h;
	t_vector	v_v;
	t_vector	lower;
	t_light		light;
	t_light		ambient;
	float		t_max;
	float		theta;
	float		depth;
	float		h;
	float		len;
	float		aspect_ratio;
	float		fov;
}	t_cam;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_hit
{
	t_vector	p;
	t_vector	normal;
	float		a;
	float		b;
	float		c;
	float		dis;
	float		t;
	float		t1;
}	t_hit;

typedef struct s_object
{
	char		*type;
	char		*texture;
	char		*reflec;
	float		radius;
	float		height;
	float		width;
	float		t_min;
	float		t_max;
	int			index;
	t_hit		ob_hit;
	t_matrix	mat;
	t_matrix 	inv;
	t_matrix 	inv_trans;
	t_matrix	re[2];
	t_vector	vector;
	t_vector	center;
	t_vector	diff;
	t_vector	t_cap;
	t_vector	b_cap;
	t_color		color;
	t_cam		cam;
}	t_object;

#endif