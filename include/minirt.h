/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:43:18 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/06 01:22:28 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include "../mlx/mlx.h"
# include "getnextline/get_next_line.h"
# include "vector.h"
# include "camera.h"
# include "object.h"
# include "color.h"
# include "antialiasing.h"
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef PI
#  define PI  3.14159
# endif

# define SC_WIDTH 1067
# define SC_HEIGHT 600
# define MIN_HIT_DIS 0.001
# define MAX_TRACE_DIS 1000.0
# define MAX_STEP 600
# define THREAD_NUM 10
# define ON_DESTROY 17
# define ON_ESCAPE 53

typedef struct s_plane
{
	char	*pl;
	t_point	ppoint;
	t_point	vector;
	t_color	color;
}	t_plane;

/*build type object to kept all information and identified which type is*/
void		create_scene(t_scene *sc, t_object *ob, t_vars *data, t_color col);
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
void		handle_scene(t_scene sc[], t_vars vars);

/*checkfile*/
t_object	*check_file(char *av, t_cam *cam, t_object *ob);
int			count_size(int fd);
int			check_fd(char *av, t_cam *cam, t_object *ob);
int			check_ratio(char *str);
int			check_rgb(char *str);
void		check_coor(char *str);
void		check_vec(char *str);
int			check_fov(char *str);
void		check_size(char *str);
int			check_range_rgb(int n);
int			check_range_vec(int n);
int			check_range_fov(int n);
int			count_dup(char *str);
int			count_dup_objectrev(char *str);
int			count_dup_envrev(char *str);
int			count_other(char *str);
void		count_split(char **split, int num, char *err);
void		exit_dup(char **split_space);
int			key_hook(int keycode, t_vars *vars);
int			close_minirt(t_vars *vars);
int			count(char **str);
int			ft_isdigit(int n);
int			file_extension(char *av);
void		free2p(char **ptr);
void		free_allobject(t_object *ob, t_cam *cam);
float		convert_to_float(char *str, int i, int sign);
float		ft_atof(char *str);
char		**ft_split_space(char const *s);

int			iden_a(t_cam *cam, char **split_space);
int			iden_c(t_cam *cam, char **split_space);
int			iden_l(t_cam *cam, char **split_space);
void		iden_pl(t_object *ob, char **split_space);
void		iden_sp(t_object *ob, char **split_space);
void		iden_cy(t_object *ob, char **split_space);
void		iden_co(t_object *ob, char **split_space);
void		write_error(char *err);
void		init_properties(t_object *ob, float ra, float he, float wid);

#endif
