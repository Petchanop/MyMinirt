/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:34:29 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/04 21:01:41 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "type.h"

int		convert_to_int(t_color color);
t_color	translate_color(t_color *c);
t_color	color_mul(t_color col, float t);
t_color	color_multiply(t_color c1, t_color c2);
t_color	color_div(t_color c, float a);
t_color	color_sub(t_color c1, t_color c2);
t_color	color_add(t_color c1, t_color c2);
t_color	generate_color(t_vector lower);
t_color	generate_obcolor(t_vector cam, t_object ob, t_vector dir, float t);

#endif