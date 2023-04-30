/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:22:40 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/29 18:37:55 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_matrix	transpose(t_matrix num, t_matrix fac, float r);

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

	ob->mat = matrix_scale(ob->mat, 2 * ob->radius, ob->height, 2 * ob->radius);
	printf("scale matrix.\n");
	printf_matrix(ob->mat);
	rotate = rotation_matrix(vector_normalize(ob->vector));
	printf("Rotation matrix.\n");
	printf_matrix(rotate);
	ob->mat = matrix_mul(&rotate, &ob->mat);
	trans = matrix_translate(ob->center);
	printf("translation.\n");
	printf_matrix(trans);
	ob->mat = matrix_mul(&trans, &ob->mat);
	printf("before inverse.\n");
	printf_matrix(ob->mat);
	det = determinant(ob->mat, 4);
	if (!det)
	{
		printf("determinant equal 0.\n");
		exit(0);
	}
	ob->inv = cofactor(ob->mat, 4);
	printf("inverse\n");
	printf_matrix(ob->inv);
	// exit(0);
}
