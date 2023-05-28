/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:43:18 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/28 23:59:26 by lkaewsae         ###   ########.fr       */
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
# include <pthread.h>
# include "../mlx/mlx.h"
# include "../include/getnextline/get_next_line.h"
# include "vector.h"
# include "camera.h"
# include "object.h"
# include "color.h"
# include "antialiasing.h"
# include "libft.h"

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
# define THREAD_NUM 10 

typedef struct s_plane
{
	char	*pl;
	t_point	ppoint;
	t_point	vector;
	t_color	color;
}	t_plane;

/*build type object to kept all information and identified which type is*/
void		create_scene(t_scene *sc, t_object *ob, t_vars *data, t_color color);
void		run_thread(t_cam *cam, t_object *ob, t_vars *data);
void		put_pixel(t_data *data, int x, int y, int color);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_vector	random_vector(float min, float max);
t_vector	rand_in_sphere( void );

//light vector function
t_vector	light_dir(t_object ob, t_cam *c);

//texture
t_vector	isreflect(t_vector v, t_vector n);

float		is_shadow(t_cam *c, t_ray r, t_object *ob);

void		*render_scene(void *sc);
void		free_scene(t_scene sc[]);

/*checkfile*/
t_object *check_file(char *av);
int check_ratio(char *str);
int check_RGB(char *str);
int check_coor(char *str);
int check_vec(char *str);
int check_FOV(char *str);
int check_size(char *str);
int check_range_RGB(int n);
int check_range_vec(int n);
int check_range_FOV(int n);
int count(char **str);
int ft_isdigit(int n);
int	file_extension(char *av);

#endif