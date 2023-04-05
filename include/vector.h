/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:41:16 by npiya-is          #+#    #+#             */
/*   Updated: 2023/03/31 18:51:11 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vector;

float		distanceto_ob(t_vector p1, t_vector p2);
float		dot_product(t_vector v1, t_vector v2);
float		vector_length(t_vector v);
float		normalize_cord(float a, float b);
t_vector	cross_product(t_vector p1, t_vector p2);
t_vector	vector_normalize(t_vector v);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_div(t_vector v1, float k);
t_vector	vector_mul(t_vector v, float k);

#endif