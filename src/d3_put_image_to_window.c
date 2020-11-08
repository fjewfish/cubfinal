/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d3_put_image_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:29:10 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 21:32:47 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

unsigned int		ft_pixel(t_aio *aio, double i)
{
	int				index;

	if (floor(aio->hit.y) == aio->hit.y
			|| floor(aio->hit.y) + 0.5 == aio->hit.y)
		index = TEX * floor(TEX * i) + TEX * (aio->hit.x - floor(aio->hit.x));
	else if (floor(aio->hit.x) == aio->hit.x
			|| floor(aio->hit.x) + 0.5 == aio->hit.x)
		index = TEX * floor(TEX * i) + TEX * (aio->hit.y - floor(aio->hit.y));
	if (floor(aio->hit.y) == aio->hit.y)
	{
		if (aio->ray.hor == 1)
			return (aio->tex.so[index]);
		else if (aio->ray.hor == 0)
			return (aio->tex.no[index]);
	}
	else if (floor(aio->hit.x) == aio->hit.x)
	{
		if (aio->ray.ver == 1)
			return (aio->tex.ea[index]);
		else if (aio->ray.ver == 0)
			return (aio->tex.we[index]);
	}
	return (GREEN);
}
