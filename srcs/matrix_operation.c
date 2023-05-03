/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:22:40 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/03 22:29:32 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_matrix	transpose(t_matrix num, t_matrix fac, float r);

t_matrix	rotate_z(float r)
{
	t_matrix	m;
	int			i;

	i = 0;
	while (i < 4)
	{
		m.m[i][0] = 0;
		m.m[i][1] = 0;
		m.m[i][2] = 0;
		m.m[i][3] = 0;
		i++;
	}	
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	m.m[0][0] = cos(r);
	m.m[0][1] = -sin(r);
	m.m[1][0] = sin(r);
	m.m[1][1] = cos(r);
	return (m);
}

t_matrix	rotate_y(float r)
{
	t_matrix	m;
	int			i;

	i = 0;
	while (i < 4)
	{
		m.m[i][0] = 0;
		m.m[i][1] = 0;
		m.m[i][2] = 0;
		m.m[i][3] = 0;
		i++;
	}
	m.m[1][1] = 1;
	m.m[3][3] = 1;
	m.m[0][0] = cos(r);
	m.m[0][2] = sin(r);
	m.m[2][0] = -sin(r);
	m.m[2][2] = cos(r);
	return (m);
}

t_matrix	rotation_matrix(t_vector obv)
{
	t_matrix	m1;
	t_matrix	m2;
	float		alpha;
	float		beta;

	alpha = atan2(sqrt(obv.x * obv.x + obv.z * obv.z), obv.y);
	beta = atan2(obv.z, obv.x);
	m1 = rotate_z(-alpha);
	m2 = rotate_y(-beta);
	m2 = matrix_mul(&m2, &m1);
	return (m2);
}

t_matrix	matrix_translate(t_vector p)
{
	t_matrix	m;
	int			i;

	i = 0;
	while (i < 4)
	{
		m.m[i][0] = 0;
		m.m[i][1] = 0;
		m.m[i][2] = 0;
		m.m[i][3] = 0;
		i++;
	}
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	m.m[0][3] = p.x;
	m.m[1][3] = p.y;
	m.m[2][3] = p.z;
	return (m);
}

t_matrix	make_identity(void)
{
	t_matrix	inv;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				inv.m[i][j] = 1;
			else
				inv.m[i][j] = 0;
		}
		i++;
	}
	return (inv);
}

float	determinant(t_matrix a, float k)
{
	float	s;
	float	det;
	t_matrix	b;
	int		i, j, m, n, c;
	s = 1;
	det = 0;
	if (k == 1)
		return (a.m[0][0]);
	c = 0;
	while (c < k)
	{
		m = 0;
		n = 0;
		i = 0;
		while (i < k)
		{
			j = 0;
			while (j < k)
			{
				b.m[i][j] = 0;
				if (i != 0 && j != c)
				{
					b.m[m][n] = a.m[i][j];
					if (n < (k - 2))
						n++;
					else
					{
						n = 0;
						m++;
					}
				}
				j++;
			}
			i++;
		}
		det = det + s * (a.m[0][c] * determinant(b, k - 1));
		s = -1 * s;
		c++;
	}
	return (det);
}

t_matrix	cofactor(t_matrix a, float f)
{
	t_matrix	b;
	t_matrix	fac;
	int	p, q, m, n, i, j;

	q = 0;
	while (q < f)
	{
		p = 0;
		while (p < f)
		{
			m = 0;
			n = 0;
			i = 0;
			while (i < f)
			{
				j = 0;
				while (j < f)
				{
					if (i != q && j != p)
					{
						b.m[m][n] = a.m[i][j];
						if (n < (f - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
					j++;
				}
				i++;
			}
			fac.m[q][p] = pow(-1, q + p) * determinant(b, f - 1);
			p++;
		}
		q++;
	}
	return (transpose(a, fac, f));
}

t_matrix	transpose(t_matrix num, t_matrix fac, float r)
{
	int			i;
	int			j;
	float		d;
	t_matrix	b;
	t_matrix	inv;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < r)
		{
			b.m[i][j] = fac.m[j][i];
			j++;
		}
		i++;
	}
	d = determinant(num, r);
	if (!d)
	{
		printf("determinant equal 0.\n");
		exit(0);
	}
	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < r)
		{
			inv.m[i][j] = b.m[i][j] / d;
			j++;
		}
		i++;
	}
	return (inv);
}

t_matrix	matrix_trans(t_matrix m)
{
	t_matrix	trans;
	uint8_t		i;
	uint8_t		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			trans.m[i][j] = m.m[j][i];
			j++;
		}
		i++;
	}
	return (trans);
}

void printf_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("mat[%d][%d] : %f ", i, j, m.m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	tranform_vectomat(t_object *ob)
{
	t_matrix	rotate;
	t_matrix	trans;
	float	det;

	ob->mat = matrix_scale(ob->mat, ob->radius, ob->height, ob->radius);
	// printf("scale matrix.\n");
	// printf_matrix(ob->mat);
	rotate = rotation_matrix(vector_normalize(ob->vector));
	// printf("Rotation matrix.\n");
	// printf_matrix(rotate);
	ob->mat = matrix_mul(&rotate, &ob->mat);
	trans = matrix_translate(ob->center);
	// printf("translation.\n");
	// printf_matrix(trans);
	ob->mat = matrix_mul(&trans, &ob->mat);
	// printf("before inverse.\n");
	// printf_matrix(ob->mat);
	det = determinant(ob->mat, 4);
	if (!det)
	{
		printf("determinant equal 0.\n");
		exit(0);
	}
	ob->inv = cofactor(ob->mat, 4);
	// printf("inverse\n");
	// printf_matrix(ob->inv);
	ob->inv_trans = matrix_trans(ob->inv);
	// printf("inverse trans\n");
	// printf_matrix(ob->inv_trans);
	ob->re[0] = matrix_scale(ob->re[0], ob->t_cap.x, ob->t_cap.y, ob->t_cap.z);
	ob->re[1] = matrix_scale(ob->re[1], ob->b_cap.x, ob->b_cap.y, ob->b_cap.z);
	ob->re[0] = matrix_mul(&ob->inv, &ob->re[0]);
	// printf("rescale h\n");
	// printf_matrix(ob->re[0]);
	ob->re[1] = matrix_mul(&ob->inv, &ob->re[1]);
	// printf("rescale c\n");
	// printf_matrix(ob->re[1]);
	ob->re[0] = matrix_sub(ob->re[0], ob->re[1]);
	// printf("h - c\n");
	// printf_matrix(ob->re[0]);
	// exit(0);
}
