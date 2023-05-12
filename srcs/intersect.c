/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:38:42 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/11 15:16:53 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	hit_object(t_object *ob, t_ray r, float t_max)
{
	if (!strcmp(ob->type, "sp"))
		return (hit_sphere(ob, r, t_max));
	else if (!strcmp(ob->type, "cy"))
		return (hit_cylinder(ob, r, t_max));
	else if (!strcmp(ob->type, "pl"))
		return (hit_plane(ob, r, t_max));
	else if (!strcmp(ob->type, "dk"))
	{
		if (hit_plane(ob, r, t_max) != -1)
			return (hit_disk(ob, r, ob->center, ob->ob_hit.t));
	}
	else if (!strcmp(ob->type, "co"))
		return (hit_cone(ob, r, t_max));
	return (-1);
}

int	find_objecthit(t_cam *c, t_ray ca, t_object *ob)
{
	int	i;
	int	idx;

	i = 0;
	idx = -1;
	while (ob[i].type)
	{
		c->id_hit = hit_object(&ob[i], ca, c->t_max);
		if (c->id_hit > -1)
		{
			c->t_max = ob[i].ob_hit.t;
			idx = c->id_hit;
		}
		i++;
	}
	return (idx);
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
		t = hit_object(&ob[i], r, c->t_max);
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
