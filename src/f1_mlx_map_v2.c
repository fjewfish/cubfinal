/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f1_mlx_map_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:53:00 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 15:16:24 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

void		ft_color_adr2(t_aio *aio, int color, unsigned int *adr)
{
	int index;

	index = 0;
	while (index < (aio->res.map_x + aio->img.coef_dylib) * aio->res.map_y)
	{
		adr[index] = color;
		index++;
	}
}

void		ft_map_mode(t_aio *aio)
{
	int		scale;
	int		i;

	i = 0;
	ft_color_adr2(aio, BLACK, aio->img.adr);
	if (aio->img.coef_dylib == 0)
		aio->img.coef_dylib = aio->img.line_length / 4 - aio->res.map_x;
	scale = ft_init_scale(aio);
	pixel_put_plr(aio, aio->plr.pos_x, aio->plr.pos_y, scale);
	ft_map_pixel_put(aio, scale);
	pixel_put_ray(aio, aio->plr.pos_x, aio->plr.pos_y, scale);
	mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);
	mlx_string_put(aio->mlx.ptr, aio->win.ptr, aio->res.map_x - 150,
									aio->res.map_y - 40, WHITE, "FJEWFISH 42");
	while (i < aio->map.sprite_count)
	{
		mlx_string_put(aio->mlx.ptr, aio->win.ptr, (int)(aio->spr[i].x * scale),
						(int)(aio->spr[i].y * scale), WHITE, "?");
		i++;
	}
	mlx_do_sync(aio->mlx.ptr);
	free(aio->hit.distance);
}

void		ft_map_mini(t_aio *aio)
{
	int		scale;

	scale = ft_init_scale(aio) / 4;
	pixel_put_plr(aio, aio->plr.pos_x, aio->plr.pos_y, scale);
	ft_map_pixel_put(aio, scale);
	pixel_put_ray(aio, aio->plr.pos_x, aio->plr.pos_y, scale);
}

int			ft_init_scale(t_aio *aio)
{
	int		max_x;
	int		max_y;
	int		scale;

	max_x = aio->res.map_x / aio->map.width;
	max_y = aio->res.map_y / aio->map.height;
	if (max_x <= max_y)
		scale = max_x;
	else
		scale = max_y;
	return (scale);
}

void		ft_map_pixel_put(t_aio *aio, int scale)
{
	int		i;
	int		j;

	i = 0;
	while (aio->map.map[i])
	{
		j = 0;
		while (aio->map.map[i][j])
		{
			if (aio->map.map[i][j] == '1')
			{
				if (i == 0 || j == 0 || i == aio->map.height - 1
					|| j == aio->map.width - 1)
					pixel_put_white(aio, j, i, scale);
				else
					pixel_put_red(aio, j, i, scale);
			}
			j++;
		}
		i++;
	}
}
