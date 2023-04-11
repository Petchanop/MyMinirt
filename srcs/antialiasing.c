/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:46:25 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/12 01:24:39 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	random_float( void )
{
	float	n;

	n = (float)rand() / RAND_MAX;
	return (n);
}

float	rand_between(float min, float max)
{
	float	n;

	n = min + (max - min) * random_float();
	return (n);
}

float	clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

t_color	super_sampling(t_cam *cam, t_object *ob, int x, int y)
{
	float		u;
	float		v;
	t_color		pixel;
	t_color		ret;
	t_vector	ray;

	ret = (t_color){0, 0, 0};
	u = ((float)x + ((float)1 / 8)) / (SCENCE_WIDTH - 1);
	v = ((float)y + ((float)3 / 8)) / (SCENCE_HEIGHT - 1);
	// ray = sampling_ray(cam, u, v);
	ray = ray_dir(cam, cam->cpoint, u, v);
	pixel = ray_color(cam, cam->cpoint, ray, ob, cam->depth);
	ret = (t_color){ret.r += pixel.r, ret.g += pixel.g, ret.b += pixel.b};
	u = ((float)x + ((float)3 / 8)) / (SCENCE_WIDTH - 1);
	v = ((float)y - ((float)1 / 8)) / (SCENCE_HEIGHT - 1);
	// ray = sampling_ray(cam, u, v);
	ray = ray_dir(cam, cam->cpoint, u, v);
	pixel = ray_color(cam, cam->cpoint, ray, ob, cam->depth);
	ret = (t_color){ret.r += pixel.r, ret.g += pixel.g, ret.b += pixel.b};
	u = ((float)x - ((float)3 / 8)) / (SCENCE_WIDTH - 1);
	v = ((float)y - ((float)1 / 8)) / (SCENCE_HEIGHT - 1);
	// ray = sampling_ray(cam, u, v);
	ray = ray_dir(cam, cam->cpoint, u, v);
	pixel = ray_color(cam, cam->cpoint, ray, ob, cam->depth);
	ret = (t_color){ret.r += pixel.r, ret.g += pixel.g, ret.b += pixel.b};
	u = ((float)x - ((float)3 / 8)) / (SCENCE_WIDTH - 1);
	v = ((float)y + ((float)1 / 8)) / (SCENCE_HEIGHT - 1);
	// ray = sampling_ray(cam, u, v);
	ray = ray_dir(cam, cam->cpoint, u, v);
	pixel = ray_color(cam, cam->cpoint, ray, ob, cam->depth);
	ret = (t_color){ret.r += pixel.r, ret.g += pixel.g, ret.b += pixel.b};
	return (ret);
}

t_vector	sampling_ray(t_cam *cam, float x, float y)
{
	t_vector	dir;

	dir.x = x * cam->v_h.x + y * cam->v_v.x + cam->lower.x;
	dir.y = x * cam->v_h.y + y * cam->v_v.y + cam->lower.y;
	dir.z = x * cam->v_h.z + y * cam->v_v.z + cam->lower.z;
	dir.w = 0;
	return (vector_normalize(dir));
}

t_color	random_sampling(t_cam *cam, t_object *ob, float x, float y)
{
	t_vector	dir;
	t_color		ret;

	dir = sampling_ray(cam, x, y);
	ret = ray_color(cam, cam->cpoint, dir, ob, cam->depth);
	return (ret);
}

t_color	generate_sampling(t_cam *cam, t_object *ob, int x, int y)
{
	t_color		ret;
	t_color		*pixel;
	float		u;
	float		v;

	pixel = malloc(sizeof(t_color));
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
	u = (float)x - 0.25;
	v = (float)y - 0.25;
	ret = random_sampling(cam, ob, u, v);
	*pixel = (t_color){ret.r += pixel->r, ret.g += pixel->g, ret.b += pixel->b};
	u = (float)x - 0.25;
	v = (float)y + 0.25;
	ret = random_sampling(cam, ob, u, v);
	*pixel = (t_color){ret.r += pixel->r, ret.g += pixel->g, ret.b += pixel->b};
	return (*pixel);
}

t_color	antialiasing(t_cam *cam, t_object *ob, int x, int y)
{
	int			i;
	t_color		ret;

	i = SAMPLE_PIXEL;
	ret = generate_sampling(cam, ob, x, y);
	ret = (t_color){(ret.r /= i), (ret.g /= i), (ret.b /= i)};
	return (translate_color(ret));
}
