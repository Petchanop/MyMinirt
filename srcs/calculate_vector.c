/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:31:43 by npiya-is          #+#    #+#             */
/*   Updated: 2023/03/31 19:00:40 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	distanceto_ob(t_vector p1, t_vector p2)
{
	float	distance;
	float	diffx;
	float	diffy;
	float	diffz;

	diffx = pow(p1.x - p2.x, 2);
	diffy = pow(p1.y - p2.y, 2);
	diffz = pow(p1.z - p2.z, 2);
	distance = sqrt(diffx + diffy + diffz);
	return (distance);
}

t_vector	cross_product(t_vector p1, t_vector p2)
{
	t_vector	cross;

	cross.x = (p1.y * p2.z) - (p1.z * p2.y);
	cross.y = (p1.z * p2.x) - (p1.x * p2.z);
	cross.z = (p1.x * p2.y) - (p1.y * p2.x);
	return (cross);
}

float	dot_product(t_vector v1, t_vector v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

float	vector_length(t_vector v)
{
	float	length;

	length = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	return (length);
}

t_vector	vector_normalize(t_vector v)
{
	float		length;
	t_vector	n_vector;

	length = vector_length(v);
	n_vector.x = v.x / length;
	n_vector.y = v.y / length;
	n_vector.z = v.z / length;
	return (n_vector);
}

float normalize_cord(float a, float b)
{
	float	n;

	n = sqrt(pow(a, 2) + pow(b, 2));
	return (n);
}
/*
int	main(void)
{
	t_point		p1;
	t_point		p2;
	float		distance;

	p1 = (t_point){-50, 0, 20};
	p2 = (t_point){0, 0, -10};
	distance = cam_distanceto_ob(p1, p2);
	printf("distance : %f\n", distance);
}*/
