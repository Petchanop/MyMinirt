/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:34:29 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/12 01:21:09 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "object.h"

int		convert_to_int(t_color color);
t_color	translate_color(t_color c);
t_color	color_mul(t_color col, float t);
t_color	color_multiply(t_color c1, t_color c2);
t_color	color_add(t_color c1, t_color c2);
t_color	generate_color(t_vector lower, float t);
t_color	generate_obcolor(t_vector cam, t_object ob, t_vector dir, float t);

#endif