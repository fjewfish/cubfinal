/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d1_put_image_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:25:23 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 23:34:11 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int					ft_main_put_image(t_aio *aio)
{
	char			*spr_print;

	ft_create_img(aio);
	if (aio->mapmod.on_off == 0 && aio->res.if_map)
		ft_map_mini(aio);
	mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);
	if (aio->res.if_map)
		mlx_string_put(aio->mlx.ptr, aio->win.ptr, aio->res.map_x - 200, 20,
							WHITE, "left to collect ");
	spr_print = ft_itoa(aio->map.sprite_count);
	if (aio->res.if_map)
		mlx_string_put(aio->mlx.ptr, aio->win.ptr, aio->res.map_x - 30, 20,
							WHITE, spr_print);
	free(spr_print);
	mlx_do_sync(aio->mlx.ptr);
ft_print_parse(aio);
	return (0);
}

void				ft_create_img(t_aio *aio)
{
	aio->hit.distance = malloc(sizeof(double) * aio->res.map_x);
	if (aio->img.coef_dylib == 0)
		aio->img.coef_dylib = aio->img.line_length / 4 - aio->res.map_x;
	aio->ray.i = 0;
	while (aio->ray.i < aio->res.map_x)
	{
		ft_tangent_ray(aio);
		ft_ray_direction(aio);
		ft_vertical(aio);
		ft_horizontal(aio);
		ft_fisheye(aio, aio->ray.i);
		aio->hit.distance[aio->ray.i] = aio->hit.d;
		if (aio->mapmod.on_off != 1)
			ft_column(aio, aio->hit.height);
		if (aio->ray.i == 0)
		{
			aio->mapmod.first_hit_x = aio->hit.x;
			aio->mapmod.first_hit_y = aio->hit.y;
		}
		aio->ray.i++;
	}
	aio->mapmod.last_hit_x = aio->hit.x;
	aio->mapmod.last_hit_y = aio->hit.y;
	if (aio->mapmod.on_off == 0)
		ft_sprite(aio);
}

void				ft_fisheye(t_aio *aio, int i)
{
	if (aio->hit.dist_hor <= aio->hit.dist_ver)
	{
		aio->hit.d = aio->hit.dist_hor;
		aio->hit.x = aio->hit.x_h;
		aio->hit.y = aio->hit.y_h;
	}
	if (aio->hit.dist_ver <= aio->hit.dist_hor)
	{
		aio->hit.d = aio->hit.dist_ver;
		aio->hit.x = aio->hit.x_v;
		aio->hit.y = aio->hit.y_v;
	}
	aio->hit.d = (double)aio->hit.d * aio->ray.fish[i];
	aio->hit.height = round(aio->res.map_y / aio->hit.d);
}

void				ft_column(t_aio *aio, int size)
{
	unsigned int	color;
	int				start;
	int				count;
	int				y_coef;
	int				index;

	y_coef = 0;
	count = ft_column_init(aio, size, &color, &start);
	while (aio->ray.i < aio->res.map_x * aio->res.map_y)
	{
		if (aio->ray.i >= start && count < size)
		{
			color = ft_pixel(aio, (double)count / size);
			count++;
		}
		else if (count == size)
			color = aio->tex.fl;
		if (color != 0xFF000000)
			aio->img.adr[INDEX] = mlx_get_color_value(aio->mlx.ptr, color);
		aio->ray.i += aio->res.map_x;
		y_coef++;
	}
	aio->ray.i -= aio->res.map_x * aio->res.map_y;
}

int					ft_column_init(t_aio *aio, int size,
									unsigned int *color, int *start)
{
	int				count;

	*start = aio->res.map_x * (aio->res.map_y - size) / 2;
	if (size > aio->res.map_y)
		count = (size - aio->res.map_y) / 2;
	else
		count = 0;
	*color = aio->tex.ce;
	return (count);
}
