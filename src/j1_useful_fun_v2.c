/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j1_useful_fun_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:25:56 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 23:35:53 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"
#include <stdio.h>
void		ft_print_parse(t_aio *aio)
{
	int		i;

	printf("MAP w=%d h=%d\n", aio->map.width, aio->map.height);
	printf("res=%dx%d\ntex\n%s\n%s\n%s\n%s\n%s\n", aio->res.map_x,
				aio->res.map_y, aio->tex.east, aio->tex.north, aio->tex.south,
				aio->tex.sprite, aio->tex.west);
	printf("PLAYER\n pos_x=%f pos_y=%f dir_x%f dir_y%f      pov%f\n",
				aio->plr.pos_x, aio->plr.pos_y, aio->plr.dir_x, aio->plr.dir_y,
				aio->plr.pov);
	printf("RAY x=%f y=%f i=%d v=%f w=%f\n", aio->ray.x, aio->ray.y,
				aio->ray.i, aio->ray.ver, aio->ray.hor);
	printf("HIT x=%f y=%f d=%f\n", aio->hit.x, aio->hit.y,
				aio->hit.d);
	printf("ERRORS:\nparse_error.settings -- %d\nmap_trigger -- %d\n",
			aio->parse_error.settings, aio->parse_error.map_trigger);
	printf("SPRITE\n Count = %d\n", aio->map.sprite_count);
	//ft_print_parse_2(aio);
}

void		ft_print_parse_2(t_aio *aio)
{
	t_list	*tmp;
	int		i;

	printf("LIST\n");
	if (aio->map.list != NULL)
	{
		tmp = aio->map.list;
		while (tmp->next)
		{
			printf("%s\n", (char *)tmp->content);
			tmp = tmp->next;
		}
	}
	printf("MAP.MAP\n");
	if (aio->map.map)
	{
		i = 0;
		while (aio->map.map[i])
		{
			printf("%s\n", aio->map.map[i]);
			i++;
		}
	}
	//ft_print_parse_3(aio);
}

void		ft_print_parse_3(t_aio *aio)
{
	int i;

	i = 0;
	while (i < aio->map.sprite_count)
	{
		printf("(%f,%f)   ", aio->spr[i].x, aio->spr[i].y);
		i++;
	}
	printf("\n");
	printf("IMG\n");
	printf("dst = (char *)(adr + (y * line_length + x * (bpp / 8)) / 4);");
	printf("\n*(unsigned int*)dst = mlx_get_color_value();\n");
	printf("adr = %d\nbits_per_pixel = %d\nline_length = %d\nendian = %d\n",
				(int)aio->img.adr, (int)aio->img.bits_per_pixel,
				(int)aio->img.line_length, (int)aio->img.endian);
	printf("COEF = %d\n", aio->img.coef_dylib);
}
