/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2_hooks_function_v2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:22:06 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 23:48:57 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

void		ft_key_s(t_aio *aio)
{
	char	c;
	double	check;

	aio->plr.pos_x -= aio->plr.dir_x * SPEED;
	check = aio->plr.pos_x - aio->plr.dir_x * SPEED;
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(check)];
	if (c == '1')
		aio->plr.pos_x += aio->plr.dir_x * SPEED;
	aio->plr.pos_y -= aio->plr.dir_y * SPEED;
	check = aio->plr.pos_y - aio->plr.dir_y * SPEED;
	c = aio->map.map[(int)floor(check)][(int)floor(aio->plr.pos_x)];
	if (c == '1')
		aio->plr.pos_y += aio->plr.dir_y * SPEED;
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	if (c == '2')
	{
		aio->map.map[POS_Y][POS_X] = '0';
		aio->map.sprite_count--;
		ft_slist(aio);
	}
}

void		ft_key_d(t_aio *aio)
{
	char	c;
	double	check;

	aio->plr.pos_x -= aio->plr.dir_y * SPEED;
	check = aio->plr.pos_x - aio->plr.dir_y * SPEED;
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(check)];
	if (c == '1')
		aio->plr.pos_x += aio->plr.dir_y * SPEED;
	aio->plr.pos_y += aio->plr.dir_x * SPEED;
	check = aio->plr.pos_y + aio->plr.dir_x * SPEED;
	c = aio->map.map[(int)floor(check)][(int)floor(aio->plr.pos_x)];
	if (c == '1')
		aio->plr.pos_y -= aio->plr.dir_x * SPEED;
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	if (c == '2')
	{
		aio->map.map[POS_Y][POS_X] = '0';
		aio->map.sprite_count--;
		ft_slist(aio);
	}
}

void		ft_key_a(t_aio *aio)
{
	char	c;
	double	check;

	aio->plr.pos_x += aio->plr.dir_y * SPEED;
	check = aio->plr.pos_x + aio->plr.dir_y * SPEED;
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(check)];
	if (c == '1')
		aio->plr.pos_x -= aio->plr.dir_y * SPEED;
	aio->plr.pos_y -= aio->plr.dir_x * SPEED;
	check = aio->plr.pos_y - aio->plr.dir_x * SPEED;
	c = aio->map.map[(int)floor(check)][(int)floor(aio->plr.pos_x)];
	if (c == '1')
		aio->plr.pos_y += aio->plr.dir_x * SPEED;
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	if (c == '2')
	{
		aio->map.map[POS_Y][POS_X] = '0';
		aio->map.sprite_count--;
		ft_slist(aio);
	}
}

void		ft_key_r(t_aio *aio)
{
	double	x;
	double	y;

	x = aio->plr.dir_x * cos(TURN) - aio->plr.dir_y * sin(TURN);
	aio->plr.dir_x = x;
	y = aio->plr.dir_y * cos(TURN) + aio->plr.dir_x * sin(TURN);
	aio->plr.dir_y = y;
	if (aio->plr.dir_y <= 0)
		aio->plr.pov = acos(aio->plr.dir_x) * 180 / M_PI;
	else
		aio->plr.pov = 360 - acos(aio->plr.dir_x) * 180 / M_PI;
}

void		ft_key_l(t_aio *aio)
{
	double	x;
	double	y;

	x = aio->plr.dir_x * cos(-TURN) - aio->plr.dir_y * sin(-TURN);
	aio->plr.dir_x = x;
	y = aio->plr.dir_y * cos(-TURN) + aio->plr.dir_x * sin(-TURN);
	aio->plr.dir_y = y;
	if (aio->plr.dir_y <= 0)
		aio->plr.pov = acos(aio->plr.dir_x) * 180 / M_PI;
	else
		aio->plr.pov = 360 - acos(aio->plr.dir_x) * 180 / M_PI;
}
