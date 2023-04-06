/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:22:12 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/06 17:00:32 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "camera.h"
# define EPSILON 1e-10
# define T_MIN 0.001
# define T_MAX 10000

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_hit
{
	t_vector	p;
	t_vector	normal;
	float		a;
	float		b;
	float		c;
	float		dis;
	float		t;
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
	t_vector	vector;
	t_vector	center;
	t_color		color;
	t_cam		cam;
}	t_object;

//initialize
void		init_object(t_object *ob, t_vector center, t_vector n, t_color rgb);
void		init_type(t_object *ob, char *type, char *reflec);

//ray
t_color		ray_color(t_cam *c, t_vector cam, t_vector dir, t_object *ob, int depth);
t_vector	ray_dir(t_cam *cam, t_vector r, float u, float v);

//sphere
int		hit_object(t_object *ob, t_vector v, t_vector cam, float t_max);
t_vector	isfront_face(t_vector v, t_vector outward, t_object *ob);
t_vector	random_hemisphere(t_vector normal);
float		dis_from_sphere(t_vector current, t_object *ob, float r);

//texture
// t_color		scatter_lambertian(t_object *ob_h, t_vector dir, int depth);
t_color		metal_reflec(t_cam *c, t_object *ob, t_object *ob_h, t_vector dir, int depth);
int			closed_object(t_object *ob);

int			near_zero(t_vector v);
int			isclose(float f1, float f2);
int			convert_to_int(t_color color);
#endif