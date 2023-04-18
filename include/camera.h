/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:51:48 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/12 19:53:58 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "type.h"

t_cam		*init_camera( void );
float		degrees_to_radians(float degrees);
t_vector	find_lowerleft(t_vector cam, t_vector v_h, t_vector v_v, t_vector w);
void init_light(t_light *light);
void	init_ambient(t_light *light);

#endif