/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:51:48 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/01 14:44:19 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "type.h"

t_cam		*init_camera(t_cam *cam, t_vector c, t_vector v, float fov);
float		degrees_to_radians(float degrees);
void		init_light(t_light *light, t_vector c, t_color color, float ratio);
void		init_ambient(t_light *light, float ratio, t_color color);

#endif