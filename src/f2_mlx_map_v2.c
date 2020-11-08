/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2_mlx_map_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:53:11 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/31 19:08:19 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

void		pixel_put_white(t_aio *aio, int x, int y, int scale)
{
	int		x_limit;
	int		y_limit;
	int		y_save;
	int		x_save;
	int		index;

	x *= scale;
	y *= scale;
	x_limit = x + scale;
	y_limit = y + scale;
	y_save = y;
	x_save = x;
	while (x < x_limit)
	{
		y = y_save;
		while (y < y_limit)
		{
			index = y * (aio->res.map_x + aio->img.coef_dylib) + x;
			aio->img.adr[index] = WHITE;
			y++;
		}
		x++;
	}
}

void		pixel_put_red(t_aio *aio, int x, int y, int scale)
{
	int		x_limit;
	int		y_limit;
	int		y_save;
	int		x_save;
	int		index;

	x *= scale;
	y *= scale;
	x_limit = x + scale;
	y_limit = y + scale;
	y_save = y;
	x_save = x;
	while (x < x_limit)
	{
		y = y_save;
		while (y < y_limit)
		{
			index = y * (aio->res.map_x + aio->img.coef_dylib) + x;
			aio->img.adr[index] = RED;
			y++;
		}
		x++;
	}
}

void		pixel_put_plr(t_aio *aio, double x, double y, int scale)
{
	double	x_limit;
	double	y_limit;
	double	y_save;
	double	x_save;
	int		index;

	x = x * scale - scale / 8;
	y = y * scale - scale / 8;
	x_limit = x + scale / 4;
	y_limit = y + scale / 4;
	y_save = y;
	x_save = x;
	while (x < x_limit)
	{
		y = y_save;
		while (y < y_limit)
		{
			index = (int)y * (aio->res.map_x + aio->img.coef_dylib) + (int)x;
			aio->img.adr[index] = GREEN;
			y++;
		}
		x++;
	}
}
