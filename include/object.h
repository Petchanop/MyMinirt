/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:22:12 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/25 23:26:05 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "type.h"
# define EPSILON 1e-10
# define T_MIN 0.001
# define T_MAX 10000

//initialize
void		init_object(t_object *ob, t_vector center, t_vector n, t_color rgb);
void		init_type(t_object *ob, char *type, char *reflec);
void		init_cylinder(t_object *ob, t_vector center, t_vector n, t_color rgb);
void		init_plane(t_object *ob, t_vector center, t_vector n, t_color rgb);
//ray
t_color		ray_color(t_cam *c, t_vector cam, t_vector dir, t_object *ob, int depth);

//hit object
int			hit(t_object *ob, float sdis, t_vector v, t_vector cam, float t_max);
int			hit_object(t_object *ob, t_vector v, t_vector cam, float t_max);
int			hit_sphere(t_object *ob, t_vector v, t_vector cam, float t_max);
int			hit_cylinder(t_object *ob, t_vector v, t_vector cam, float t_max);
int			hit_plane(t_object *ob, t_vector v, t_vector cam, float t_max);
int			hit_disk(t_object *ob, t_vector v, t_vector cam, t_vector p, float t);

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