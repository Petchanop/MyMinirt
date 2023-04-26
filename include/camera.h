/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:51:48 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/20 18:33:41 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "type.h"

t_cam		*init_camera( void );
float		degrees_to_radians(float degrees);
void		init_light(t_light *light);
void		init_ambient(t_light *light);

#endif