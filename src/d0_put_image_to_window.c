/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d0_put_image_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:33:45 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 14:03:34 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

void		ft_pre_put_image(t_aio *aio)
{
	double	angle;
	double	radian;
	int		ray;
	int		half_x;

	ray = 0;
	half_x = aio->res.map_x / 2;
	aio->ray.cos = (double *)malloc(sizeof(double) * aio->res.map_x);
	aio->ray.sin = (double *)malloc(sizeof(double) * aio->res.map_x);
	aio->ray.fish = (double *)malloc(sizeof(double) * aio->res.map_x);
	angle = -33;
	while (ray < aio->res.map_x)
	{
		radian = angle * M_PI / 180;
		aio->ray.sin[ray] = sin(radian);
		aio->ray.cos[ray] = cos(radian);
		aio->ray.fish[ray] = aio->ray.cos[ray];
		angle += 66 / (double)aio->res.map_x;
		ray++;
	}
}
