/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e1_hooks_function_v2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:20:58 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 21:35:16 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int			ft_press(int key, t_aio *aio)
{
	if (key == ESC)
		aio->key.e = 1;
	else if (key == W)
		aio->key.w = 1;
	else if (key == A)
		aio->key.a = 1;
	else if (key == S)
		aio->key.s = 1;
	else if (key == D)
		aio->key.d = 1;
	else if (key == LEFT)
		aio->key.l = 1;
	else if (key == RIGHT)
		aio->key.r = 1;
	else if (key == F && aio->mapmod.on_off == 0)
		aio->mapmod.on_off = 1;
	else if (key == F)
		aio->mapmod.on_off = 0;
	return (1);
}

int			ft_release(int key, t_aio *aio)
{
	if (key == ESC)
		aio->key.e = 0;
	else if (key == W)
		aio->key.w = 0;
	else if (key == A)
		aio->key.a = 0;
	else if (key == S)
		aio->key.s = 0;
	else if (key == D)
		aio->key.d = 0;
	else if (key == LEFT)
		aio->key.l = 0;
	else if (key == RIGHT)
		aio->key.r = 0;
	return (1);
}

int			ft_key(t_aio *aio)
{
	if (aio->key.e)
		ft_close(aio, 1);
	if (aio->key.w)
		ft_key_w(aio);
	if (aio->key.s)
		ft_key_s(aio);
	if (aio->key.a)
		ft_key_a(aio);
	if (aio->key.d)
		ft_key_d(aio);
	if (aio->key.l)
		ft_key_l(aio);
	if (aio->key.r)
		ft_key_r(aio);
	if (aio->mapmod.on_off == 0 || !aio->res.if_map)
		ft_main_put_image(aio);
	if (aio->mapmod.on_off == 1 && aio->res.if_map)
	{
		ft_create_img(aio);
		ft_map_mode(aio);
	}
	return (1);
}

void		ft_key_w(t_aio *aio)
{
	char	c;
	double	check;

	aio->plr.pos_x += aio->plr.dir_x * SPEED;
	check = aio->plr.pos_x + aio->plr.dir_x * SPEED;
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(check)];
	if (c == '1')
		aio->plr.pos_x -= aio->plr.dir_x * SPEED;
	aio->plr.pos_y += aio->plr.dir_y * SPEED;
	check = aio->plr.pos_y + aio->plr.dir_y * SPEED;
	c = aio->map.map[(int)floor(check)][(int)floor(aio->plr.pos_x)];
	if (c == '1')
		aio->plr.pos_y -= aio->plr.dir_y * SPEED;
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	if (c == '2')
	{
		aio->map.map[POS_Y][POS_X] = '0';
		aio->map.sprite_count--;
		ft_slist(aio);
	}
}
