/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:38:58 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/12 00:56:54 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	random_vector(float min, float max)
{
	t_vector	ran;

	ran.x = rand_between(min, max);
	ran.y = rand_between(min, max);
	ran.z = rand_between(min, max);
	ran.w = rand_between(min, max);
	return (ran);
}

t_vector	rand_in_sphere( void )
{
	t_vector	p;

	while (1)
	{
		p = random_vector(-1, 1);
		if (vector_length(p) >= 1)
			continue ;
		return (p);
	}
}
