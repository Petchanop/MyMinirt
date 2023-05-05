/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:46:25 by npiya-is          #+#    #+#             */
/*   Updated: 2023/05/05 23:37:56 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	sampling_ray(t_cam *cam, float x, float y)
{
	t_vector	dir;

	dir.x = x * cam->u.x + y * cam->v.x + cam->lower.x;
	dir.y = x * cam->u.y + y * cam->v.y + cam->lower.y;
	dir.z = x * cam->u.z + y * cam->v.z + cam->lower.z;
	dir.w = 0;
	return (vector_normalize(dir));
}

t_color	random_sampling(t_cam *cam, t_object *ob, float x, float y)
{
	t_vector	dir;
	t_color		ret;

	dir = sampling_ray(cam, x, y);
	cam->ray.dir = dir;
	cam->ray.origin = cam->cpoint;
	ret = ray_color(cam, cam->ray, ob, cam->depth);
	return (ret);
}

t_color	*half_sampling(t_cam *cam, t_object *ob, int x, int y)
{
	t_color		ret;
	t_color		*pixel;
	float		u;
	float		v;

	pixel = malloc(sizeof(t_color));
	pixel->r = 0;
	pixel->g = 0;
	pixel->b = 0;
	u = (float)x - 0.25;
	v = (float)y - 0.25;
	ret = random_sampling(cam, ob, u, v);
	*pixel = (t_color){ret.r += pixel->r, ret.g += pixel->g, ret.b += pixel->b};
	u = (float)x - 0.25;
	v = (float)y + 0.25;
	ret = random_sampling(cam, ob, u, v);
	*pixel = (t_color){ret.r += pixel->r, ret.g += pixel->g, ret.b += pixel->b};
	return (pixel);
}

t_color	*generate_sampling(t_cam *cam, t_object *ob, int x, int y)
{
	t_color		ret;
	t_color		*h;
	t_color		*pixel;
	float		u;
	float		v;

	pixel = malloc(sizeof(t_color));
	pixel->r = 0;
	pixel->g = 0;
	pixel->b = 0;
	ret = random_sampling(cam, ob, x, y);
	*pixel = (t_color){ret.r += pixel->r, ret.g += pixel->g, ret.b += pixel->b};
	u = (float)x + 0.25;
	v = (float)y + 0.25;
	ret = random_sampling(cam, ob, u, v);
	*pixel = (t_color){ret.r += pixel->r, ret.g += pixel->g, ret.b += pixel->b};
	u = (float)x + 0.25;
	v = (float)y - 0.25;
	ret = random_sampling(cam, ob, u, v);
	*pixel = (t_color){ret.r += pixel->r, ret.g += pixel->g, ret.b += pixel->b};
	h = half_sampling(cam, ob, x, y);
	*pixel = (t_color){h->r += pixel->r, h->g += pixel->g, h->b += pixel->b};
	*pixel = color_div(*pixel, SAMPLE_PIXEL);
	free(h);
	return (pixel);
}

t_color	antialiasing(t_cam *cam, t_object *ob, int x, int y)
{
	t_color		*ret;

	ret = generate_sampling(cam, ob, x, y);
	return (translate_color(ret));
}
