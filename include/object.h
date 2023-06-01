/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:22:12 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/01 16:25:34 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "type.h"
# define EPSILON 1e-10
# define T_MIN 0.001
# define T_MAX 10000

//initialize
void		init_sphere(t_object *ob, char **c, char **col);
void		init_type(t_object *ob, char *type, char *reflec);
void		init_cylinder(t_object *ob, char **c, char **v, char **col);
void		init_plane(t_object *ob, char **c, char **v, char **col);
void		init_disk(t_object *ob, t_vector center, t_vector n, t_color rgb);
void		init_cone(t_object *ob, char **c, char **v, char **col);
//ray
t_color		ray_color(t_cam *c, t_ray ca, t_object *ob, int depth);

//hit object
int			find_objecthit(t_cam *c, t_ray ca, t_object *ob);
int			hit(t_object *ob, float sdis, t_ray r, float t_max);
int			hit_object(t_object *ob, t_ray r, float t_max);
int			hit_sphere(t_object *ob, t_ray r, float t_max);
int			hit_cylinder(t_object *ob, t_ray r, float t_max);
int			hit_plane(t_object *ob, t_ray r, float t_max);
int			hit_disk(t_object *ob, t_ray r, t_vector p, float t);
int			hit_cone(t_object *ob, t_ray r, float t_max);

//hit object utility
int			hit_body(t_object *ob, t_ray r, float t[], int inside);
int			hit_cap(t_object *ob, t_ray r, float t_max);

t_vector	isfront_face(t_vector v, t_vector outward, t_object *ob);
t_vector	random_hemisphere(t_vector normal);
//texture
// t_color		scatter_lambertian(t_object *ob_h, t_vector dir, int depth);
t_ray		metal_reflec(t_object *ob_h, t_vector dir);

//shading
float		compute_shade(t_cam *c, t_vector p, t_vector s);
float		compute_specular(t_cam *c, t_vector p, t_vector s);

int			convert_to_int(t_color color);
#endif
