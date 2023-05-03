/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:36:52 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/02 17:27:32 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_matrix	vectomatrix(t_vector *p)
{
	t_matrix	m;
	int			i;

	i = 0;
	while (i < 4)
	{
		m.m[i][0] = p[i].x;
		m.m[i][1] = p[i].y;
		m.m[i][2] = p[i].z;
		m.m[i][3] = p[i].w;
		i++;
	}
	return (m);
}

t_matrix	matrix_scale(t_matrix m, float x, float y, float z)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		m.m[i][0] = 0;
		m.m[i][1] = 0;
		m.m[i][2] = 0;
		m.m[i][3] = 0;
		i++;
	}
	m.m[0][0] = x;
	m.m[1][1] = y;
	m.m[2][2] = z;
	m.m[3][3] = 1;
	return (m);
}

t_matrix	matrix_mul(t_matrix *a, t_matrix *b)
{
	t_matrix	m;
	int			i;

	i = 0;
	while (i < 4)
	{
		m.m[i][0] = a->m[i][0] * b->m[0][0] + a->m[i][1] * b->m[1][0] + a->m[i][2] * b->m[2][0] + a->m[i][3] * b->m[3][0];
		m.m[i][1] = a->m[i][0] * b->m[0][1] + a->m[i][1] * b->m[1][1] + a->m[i][2] * b->m[2][1] + a->m[i][3] * b->m[3][1];
		m.m[i][2] = a->m[i][0] * b->m[0][2] + a->m[i][1] * b->m[1][2] + a->m[i][2] * b->m[2][2] + a->m[i][3] * b->m[3][2];
		m.m[i][3] = a->m[i][0] * b->m[0][3] + a->m[i][1] * b->m[1][3] + a->m[i][2] * b->m[2][3] + a->m[i][3] * b->m[3][3];
		i++;
	}
	return (m);
}

t_vector	matrix_tmul(t_matrix m, t_vector n)
{
	t_vector	trans;

	trans.x = m.m[0][0] * n.x + m.m[0][1] * n.y + m.m[0][2] * n.z
		+ m.m[0][3] * n.w;
	trans.y = m.m[1][0] * n.x + m.m[1][1] * n.y + m.m[1][2] * n.z
		+ m.m[1][3] * n.w;
	trans.z = m.m[2][0] * n.x + m.m[2][1] * n.y + m.m[2][2] * n.z
		+ m.m[2][3] * n.w;
	trans.w = m.m[3][0] * n.x + m.m[3][1] * n.y + m.m[3][2] * n.z
		+ m.m[3][3] * n.w;
	return (trans);
}

t_matrix	matrix_sub(t_matrix a, t_matrix b)
{
	t_matrix	res;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.m[i][j] = a.m[i][j] - b.m[i][j];
			j++;
		}
		i++;
	}
	return (res);
}
