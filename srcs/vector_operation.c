/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:05:50 by npiya-is          #+#    #+#             */
/*   Updated: 2023/03/31 19:05:54 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	vector_add(t_vector v1, t_vector v2)
{
	t_vector	add;

	add.x = v1.x + v2.x;
	add.y = v1.y + v2.y;
	add.z = v1.z + v2.z;
	return (add);
}

t_vector	vector_sub(t_vector v1, t_vector v2)
{
	t_vector	sub;

	sub.x = v1.x - v2.x;
	sub.y = v1.y - v2.y;
	sub.z = v1.z - v2.z;
	return (sub);
}

t_vector	vector_div(t_vector v1, float k)
{
	t_vector	div;

	div.x = v1.x / k;
	div.y = v1.y / k;
	div.z = v1.z / k;
	return (div);
}

t_vector	vector_mul(t_vector v, float k)
{
	t_vector	vector_mul;

	vector_mul.x = v.x * k;
	vector_mul.y = v.y * k;
	vector_mul.z = v.z * k;
	return (vector_mul);
}

t_vector	vector_multiply(t_vector v, t_vector u)
{
	t_vector	vec;

	vec.x = v.x * u.x;
	vec.y = v.y * u.y;
	vec.z = v.z * v.z;
	return (vec);
}
