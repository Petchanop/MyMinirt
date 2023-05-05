/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:49:44 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 23:23:18 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTIALIASING_H
# define ANTIALIASING_H

# define SAMPLE_PIXEL 5

# include "type.h"

float		clamp(float x, float min, float max);
float		random_float( void );
float		rand_between(float min, float max);
t_color		antialiasing(t_cam *cam, t_object *ob, int x, int y);
t_vector	sampling_ray(t_cam *cam, float x, float y);
t_color		random_sampling(t_cam *cam, t_object *ob, float x, float y);
t_color		*generate_sampling(t_cam *cam, t_object *ob, int x, int y);

#endif