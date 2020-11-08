/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2_put_image_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:29:07 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 20:51:39 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

void	ft_tangent_ray(t_aio *aio)
{
	double sin;
	double cos;

	sin = aio->ray.sin[aio->ray.i];
	cos = aio->ray.cos[aio->ray.i];
	aio->ray.x = aio->plr.dir_x * cos - aio->plr.dir_y * sin;
	aio->ray.y = aio->plr.dir_y * cos + aio->plr.dir_x * sin;
	aio->ray.tan_h = aio->ray.x / aio->ray.y;
	aio->ray.tan_v = aio->ray.y / aio->ray.x;
}

void	ft_ray_direction(t_aio *aio)
{
	if (aio->ray.x >= 0)
		aio->ray.ver = 1;
	else
		aio->ray.ver = 0;
	if (aio->ray.y >= 0)
		aio->ray.hor = 1;
	else
		aio->ray.hor = 0;
}

void	ft_vertical(t_aio *aio)
{
	double	x;
	double	y;
	char	wall;

	aio->hit.dist_ver = MAX;
	x = floor(aio->plr.pos_x) + aio->ray.ver;
	y = aio->plr.pos_y + (x - aio->plr.pos_x) * aio->ray.tan_v;
	while ((int)floor(y) > 0 && (int)floor(y) < aio->map.height)
	{
		wall = aio->map.map[(int)floor(y)][(int)floor(x - 1 + aio->ray.ver)];
		if (wall == '1')
		{
			aio->hit.x_v = x;
			aio->hit.y_v = y;
			aio->hit.dist_ver = hypot(x - aio->plr.pos_x, y - aio->plr.pos_y);
			return ;
		}
		x += (2 * aio->ray.ver - 1);
		y += (2 * aio->ray.ver - 1) * aio->ray.tan_v;
	}
}

void	ft_horizontal(t_aio *aio)
{
	double	y;
	double	x;
	char	wall;

	aio->hit.dist_hor = MAX;
	y = floor(aio->plr.pos_y) + aio->ray.hor;
	x = aio->plr.pos_x + (y - aio->plr.pos_y) * (aio->ray.tan_h);
	while ((int)floor(x) > 0 && (int)floor(x) < aio->map.width)
	{
		wall = aio->map.map[(int)floor(y - 1 + aio->ray.hor)][(int)floor(x)];
		if (wall == '1')
		{
			aio->hit.x_h = x;
			aio->hit.y_h = y;
			aio->hit.dist_hor = hypot(x - aio->plr.pos_x, y - aio->plr.pos_y);
			return ;
		}
		y += (2 * aio->ray.hor - 1);
		x += (2 * aio->ray.hor - 1) * aio->ray.tan_h;
	}
}
