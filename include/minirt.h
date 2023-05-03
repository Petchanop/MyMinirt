/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:43:18 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/02 15:44:28 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../include/getnextline/get_next_line.h"
# include "vector.h"
# include "camera.h"
# include "object.h"
# include "color.h"
# include "antialiasing.h"
# include "matrix.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096 
# endif

# ifndef PI
#  define PI  3.14159
# endif

# define SCENCE_WIDTH 1067
# define SCENCE_HEIGHT 600
# define MIN_HIT_DIS 0.001
# define MAX_TRACE_DIS 1000.0
# define MAX_STEP 600;

typedef struct s_data {
	void	*img;
	char	*addr;
	float	zoom;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		depth;
	int		width;
}	t_data;

typedef struct s_vars {
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_point		zoom;
	float		angle;
	float		angle1;
	float		angle2;
}	t_vars;

typedef struct s_plane
{
	char	*pl;
	t_point	ppoint;
	t_point	vector;
	t_color	color;
}	t_plane;

/*build type object to kept all information and identified which type is*/
void		create_background(t_cam *cam, t_object *ob, t_vars *data, t_color color);
void		put_pixel(t_data *data, int x, int y, int color);
void		write_line(t_vars vars, t_point point[2], t_color color);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
float		find_stepxy(t_point diff);
float		find_stepxz(t_point diff);
int			check_point(t_point begin, t_point end, t_point step);
t_point		find_dxdy(t_point start, t_point end);
t_point		rotatez(t_point pnt, t_vars vars);
t_point		rotatex(t_point pnt, t_vars vars);
t_point		rotatey(t_point pnt, t_vars vars);
t_point		point_transformation(t_point pnt, t_vars vars);
t_vector	random_vector(float min, float max);
t_vector	rand_in_sphere( void );

//texture
t_vector	isreflect(t_vector v, t_vector n);
t_vector	diffuse_mat(t_object ob, t_cam *c, t_vector dir);
t_vector	specular_mat(t_object ob, t_cam *c, t_vector dir);
// t_color	diffuse_mat(t_object *ob, t_cam *c, t_vector p, t_vector n, int depth);
float	is_shadow(t_cam *c, t_vector cam, t_vector ldir, t_object *ob, int idx);
t_color	light_color(t_object *ob, t_cam *c, int depth);

#endif