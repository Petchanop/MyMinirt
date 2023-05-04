/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:38:42 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/04 15:52:30 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	hit_object(t_object *ob, t_vector v, t_vector cam, float t_max)
{
	if (!strcmp(ob->type, "sp"))
		return (hit_sphere(ob, v, cam, t_max));
	else if (!strcmp(ob->type, "cy"))
		return (hit_cylinder(ob, v, cam, t_max));
	else if (!strcmp(ob->type, "pl"))
		return (hit_plane(ob, v, cam, t_max));
	else if (!strcmp(ob->type, "dk"))
	{
		if (hit_plane(ob, v, cam, t_max) != -1)
			return (hit_disk(ob, v, cam, ob->center, ob->ob_hit.t));
	}
	return (-1);
}

float	is_shadow(t_cam *c, t_ray r, t_object *ob)
{
	int		i;
	int		t;
	int		id;

	i = 0;
	id = -1;
	t = -1;
	while (ob[i].type)
	{
		t = hit_object(&ob[i], r.dir, r.origin, c->t_max);
		if (t != -1)
		{
			c->t_max = ob[i].ob_hit.t;
			id = t;
		}
		i++;
	}
	c->t_max = T_MAX;
	if (id > -1)
		return (id);
	return (-1);
}