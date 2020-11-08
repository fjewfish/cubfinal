/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g1_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:59:02 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 18:06:21 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int					ft_slist(t_aio *aio)
{
	int				i;
	int				j;
	int				k;

	free(aio->spr);
	if (!(aio->spr = malloc(sizeof(t_spr) * aio->map.sprite_count)))
		return (-1);
	i = 0;
	j = 0;
	while (j < aio->map.height)
	{
		k = 0;
		while (k < aio->map.width)
		{
			if (aio->map.map[j][k] == '2')
			{
				aio->spr[i].y = (double)j + 0.5;
				aio->spr[i++].x = (double)k + 0.5;
			}
			k++;
		}
		j++;
	}
	return (1);
}

void				ft_sprite(t_aio *aio)
{
	int				i;
	double			dist;
	double			dy;
	double			dx;

	dist = hypot(aio->plr.dir_x, aio->plr.dir_y);
	if (aio->plr.dir_y <= 0)
		aio->plr.pov = acos(aio->plr.dir_x / dist) * 180 / M_PI;
	else
		aio->plr.pov = 360 - acos(aio->plr.dir_x / dist) * 180 / M_PI;
	i = -1;
	while (++i < aio->map.sprite_count)
	{
		dx = aio->spr[i].x - aio->plr.pos_x;
		dy = aio->spr[i].y - aio->plr.pos_y;
		aio->spr[i].d = hypot(dx, dy);
	}
	ft_sorder(aio);
	i = 0;
	while (i < aio->map.sprite_count)
	{
		ft_slocate(aio, aio->spr[i].x, aio->spr[i].y, aio->spr[i].d);
		i++;
	}
	free(aio->hit.distance);
}

void				ft_sorder(t_aio *aio)
{
	t_spr			tmp;
	int				i;
	int				j;

	i = 0;
	while (i < aio->map.sprite_count - 1)
	{
		j = i + 1;
		while (j < aio->map.sprite_count)
		{
			if (aio->spr[i].d < aio->spr[j].d)
			{
				tmp = aio->spr[i];
				aio->spr[i] = aio->spr[j];
				aio->spr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void				ft_slocate(t_aio *aio, double dirx,
								double diry, double dist)
{
	double			angle;

	dirx = (dirx - aio->plr.pos_x) / dist;
	diry = (diry - aio->plr.pos_y) / dist;
	if (diry <= 0)
		angle = acos(dirx) * 180 / M_PI;
	else
		angle = 360 - acos(dirx) * 180 / M_PI;
	angle = aio->plr.pov - angle + 33;
	if (angle >= 180)
		angle -= 360;
	else if (angle <= -180)
		angle += 360;
	ft_sdraw(aio, angle * aio->res.map_x / 66, dist);
}

void				ft_sdraw(t_aio *aio, int loc, double dist)
{
	double			size;
	double			tmp;

	size = (aio->res.map_y / dist);
	tmp = (aio->res.map_x / dist);
	if (size > tmp)
		size = tmp;
	loc = loc - size / 2;
	ft_put_sprite(aio, loc, dist, size);
}
