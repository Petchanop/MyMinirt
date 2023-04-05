/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:46:25 by npiya-is          #+#    #+#             */
/*   Updated: 2023/04/05 13:23:57 by npiya-is         ###   ########.fr       */
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
	ray = ray_dir(cam, cam->cpoint, u, v);
	pixel = ray_color(cam->cpoint, ray, ob, cam->depth);
	ret = (t_color){ret.r += pixel.r, ret.g += pixel.g, ret.b += pixel.b};
	u = ((float)x + ((float)3 / 8)) / (SCENCE_WIDTH - 1);
	v = ((float)y - ((float)1 / 8)) / (SCENCE_HEIGHT - 1);
	ray = ray_dir(cam, cam->cpoint, u, v);
	pixel = ray_color(cam->cpoint, ray, ob, cam->depth);
	ret = (t_color){ret.r += pixel.r, ret.g += pixel.g, ret.b += pixel.b};
	u = ((float)x - ((float)3 / 8)) / (SCENCE_WIDTH - 1);
	v = ((float)y - ((float)1 / 8)) / (SCENCE_HEIGHT - 1);
	ray = ray_dir(cam, cam->cpoint, u, v);
	pixel = ray_color(cam->cpoint, ray, ob, cam->depth);
	ret = (t_color){ret.r += pixel.r, ret.g += pixel.g, ret.b += pixel.b};
	u = ((float)x - ((float)3 / 8)) / (SCENCE_WIDTH - 1);
	v = ((float)y + ((float)1 / 8)) / (SCENCE_HEIGHT - 1);
	ray = ray_dir(cam, cam->cpoint, u, v);
	pixel = ray_color(cam->cpoint, ray, ob, cam->depth);
	ret = (t_color){ret.r += pixel.r, ret.g += pixel.g, ret.b += pixel.b};
	return (ret);
}

t_color	antialiasing(t_cam *cam, t_object *ob, int x, int y)
{
	int		i;
	t_color	ret;

	ret = super_sampling(cam, ob, x, y);
	i = SAMPLE_PIXEL;
	ret = (t_color){(ret.r /= i), (ret.g /= i), (ret.b /= i)};
	ret.r = clamp(sqrt(ret.r), 0.0, 0.99);
	ret.g = clamp(sqrt(ret.g), 0.0, 0.99);
	ret.b = clamp(sqrt(ret.b), 0.0, 0.99);
	ret = (t_color){ret.r * 255.999, ret.g * 255.999, ret.b * 255.999};
	return (ret);
}
