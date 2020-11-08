/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f3_mlx_map_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:53:15 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/31 19:08:23 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

/*
** function line(int x0, int x1, int y0, int y1)
**      int deltax := abs(x1 - x0)
**      int deltay := abs(y1 - y0)
**      int error := 0
**      int deltaerr := (deltay + 1)
**      int y := y0
**      int diry := y1 - y0
**      if diry > 0
**          diry = 1
**      if diry < 0
**          diry = -1
**      for x from x0 to x1
**          plot(x,y)
**          error := error + deltaerr
**          if error >= (deltax + 1)
**              y := y + diry
**              error := error - (deltax + 1)
*/

void			pixel_put_ray(t_aio *aio, double x, double y, int scale)
{
	t_minimap	mm;

	mm = ft_mm_init_right(aio, x, y, scale);
	if (mm.delta_y <= mm.delta_x)
		while_1(mm, aio);
	else
		while_2(mm, aio);
	mm = ft_mm_init_left(aio, x, y, scale);
	if (mm.delta_y <= mm.delta_x)
		while_1(mm, aio);
	else
		while_2(mm, aio);
}

void			while_1(t_minimap mm, t_aio *aio)
{
	int			index;

	while (mm.x0 != mm.x1)
	{
		index = mm.y0 * (aio->img.coef_dylib + aio->res.map_x) + mm.x0;
		aio->img.adr[index] = PURPLE;
		mm.error += mm.delta_err;
		if (mm.error >= (mm.delta_x + 1))
		{
			mm.y0 += mm.diry;
			mm.error -= (mm.delta_x + 1);
		}
		mm.x0 += mm.diry2;
	}
}

void			while_2(t_minimap mm, t_aio *aio)
{
	int			index;

	while (mm.y0 != mm.y1)
	{
		index = mm.y0 * (aio->img.coef_dylib + aio->res.map_x) + mm.x0;
		aio->img.adr[index] = PURPLE;
		mm.error2 += mm.delta_err2;
		if (mm.error2 >= (mm.delta_y + 1))
		{
			mm.x0 += mm.diry2;
			mm.error2 -= (mm.delta_y + 1);
		}
		mm.y0 += mm.diry;
	}
}

t_minimap		ft_mm_init_right(t_aio *aio, double x, double y, int scale)
{
	t_minimap	mm;

	mm.x0 = (int)(x * (double)scale);
	mm.y0 = (int)(y * (double)scale);
	mm.x1 = (int)(aio->hit.x * (double)scale);
	mm.y1 = (int)(aio->hit.y * (double)scale);
	mm.delta_x = abs(mm.x1 - mm.x0);
	mm.delta_y = abs(mm.y1 - mm.y0);
	mm.error = 0;
	mm.delta_err = mm.delta_y + 1;
	mm.error2 = 0;
	mm.delta_err2 = mm.delta_x + 1;
	mm.diry = mm.y1 - mm.y0;
	if (mm.diry > 0)
		mm.diry = 1;
	if (mm.diry < 0)
		mm.diry = -1;
	mm.diry2 = mm.x1 - mm.x0;
	if (mm.diry2 > 0)
		mm.diry2 = 1;
	if (mm.diry2 < 0)
		mm.diry2 = -1;
	return (mm);
}

t_minimap		ft_mm_init_left(t_aio *aio, double x, double y, int scale)
{
	t_minimap	mm;

	mm.x0 = (int)(x * (double)scale);
	mm.y0 = (int)(y * (double)scale);
	mm.x1 = (int)(aio->mapmod.first_hit_x * (double)scale);
	mm.y1 = (int)(aio->mapmod.first_hit_y * (double)scale);
	mm.delta_x = abs(mm.x1 - mm.x0);
	mm.delta_y = abs(mm.y1 - mm.y0);
	mm.error = 0;
	mm.delta_err = mm.delta_y + 1;
	mm.error2 = 0;
	mm.delta_err2 = mm.delta_x + 1;
	mm.diry = mm.y1 - mm.y0;
	if (mm.diry > 0)
		mm.diry = 1;
	if (mm.diry < 0)
		mm.diry = -1;
	mm.diry2 = mm.x1 - mm.x0;
	if (mm.diry2 > 0)
		mm.diry2 = 1;
	if (mm.diry2 < 0)
		mm.diry2 = -1;
	return (mm);
}
