/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:43:18 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/04 15:57:59 by npiya-is         ###   ########.fr       */
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
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_vector	random_vector(float min, float max);
t_vector	rand_in_sphere( void );

//light vector function
t_vector	light_dir(t_object ob, t_cam *c);

//texture
t_vector	isreflect(t_vector v, t_vector n);
t_vector	specular_mat(t_object ob, t_cam *c, t_vector dir);

float		is_shadow(t_cam *c, t_ray r, t_object *ob);
t_color		light_color(t_object *ob, t_cam *c, int depth);

#endif