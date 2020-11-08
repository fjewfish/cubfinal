/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:28:35 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 15:16:47 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

void				ft_put_sprite(t_aio *aio, int loc, double dist, double size)
{
	unsigned int	col;
	int				x;
	int				y;
	int				index;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while ((loc + x >= 0 && loc + x < aio->res.map_x) &&
				(++y < size && aio->hit.distance[loc + x] > dist))
		{
			index = loc + x + (RES_Y / 2 + y - (int)size / 2) * (RES_X + COEF);
			if (index >= 0)
			{
				col = (double)x / size * TEX;
				col += TEX * floor(TEX * (double)y / size);
				col = aio->tex.sp[col];
				if (index < (aio->res.map_x + COEF) * aio->res.map_y)
					aio->img.adr[index] = ft_spixel(aio, index, col);
			}
		}
	}
}

unsigned int		ft_spixel(t_aio *aio, int index, unsigned int col)
{
	int				t;
	int				r;
	int				g;
	int				b;

	if (col >= 0xFF000000)
		return (aio->img.adr[index]);
	else if (col < 256 * 256 * 256)
		return (col);
	t = col / (256 * 256 * 256);
	r = (col / (256 * 256) % 256) * (1 - (double)t / 256);
	g = (col / 256 % 256) * (1 - (double)t / 256);
	b = (col % 256) * (1 - (double)t / 256);
	r += (aio->img.adr[index] / (256 * 256) % 256) * ((double)t / 256);
	g += (aio->img.adr[index] / 256 % 256) * ((double)t / 256);
	b += (aio->img.adr[index] % 256) * ((double)t / 256);
	return (r * 256 * 256 + g * 256 + b);
}
