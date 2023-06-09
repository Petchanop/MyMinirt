/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:41:16 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/01 14:08:17 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "type.h"

float		dot_product(t_vector v1, t_vector v2);
float		vector_length(t_vector v);
float		min(float a, float b);
t_vector	cross_product(t_vector p1, t_vector p2);
t_vector	vector_normalize(t_vector v);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_div(t_vector v1, float k);
t_vector	vector_mul(t_vector v, float k);
t_vector	vector_multiply(t_vector v, t_vector u);

#endif