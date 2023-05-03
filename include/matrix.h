/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:39:45 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/02 17:27:14 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "type.h"

t_matrix	vectomatrix(t_vector *p);
t_matrix	matrix_scale(t_matrix m, float x, float y, float z);
t_matrix	matrix_mul(t_matrix *a, t_matrix *b);
t_vector	matrix_tmul(t_matrix m, t_vector n);
t_matrix	transpose(t_matrix num, t_matrix fac, float r);
t_matrix	rotate_z(float r);
t_matrix	rotate_y(float r);
t_matrix	rotation_matrix(t_vector obv);
t_matrix	matrix_translate(t_vector p);
t_matrix	make_identity(void);
t_matrix	cofactor(t_matrix a, float f);
t_matrix	transpose(t_matrix num, t_matrix fac, float r);
t_matrix	matrix_sub(t_matrix a, t_matrix b);
t_matrix	matrix_trans(t_matrix m);
float		determinant(t_matrix a, float k);
void		printf_matrix(t_matrix m);

#endif