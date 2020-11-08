/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:58:28 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 14:13:54 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

void		ft_recursive_while(char **map_p, t_aio *aio)
{
	int		i;
	int		j;

	i = -1;
	while (map_p[++i])
	{
		j = -1;
		while (map_p[i][++j])
			if (map_p[i][j] == '0')
				ft_recursive_paint_algorithm(i, j, map_p, aio);
	}
	i = 0;
	while (++i < aio->map.height)
	{
		j = 0;
		while (++j < aio->map.width)
			if (map_p[i][j] == ' ' && (map_p[i + 1][j] == '*'
					|| map_p[i - 1][j] == '*' || map_p[i][j + 1] == '*' ||
					map_p[i][j - 1] == '*'))
				map_p[i][j] = '@';
	}
}

int			ft_recursive_paint_algorithm(int y, int x, char **map_p,
										t_aio *aio)
{
	if (map_p[y][x] != '0')
		return (1);
	map_p[y][x] = '*';
	if (y + 1 <= aio->map.height)
		ft_recursive_paint_algorithm(y + 1, x, map_p, aio);
	if (y - 1 > 0)
		ft_recursive_paint_algorithm(y - 1, x, map_p, aio);
	if (x + 1 <= aio->map.width)
		ft_recursive_paint_algorithm(y, x + 1, map_p, aio);
	if (x - 1 > 0)
		ft_recursive_paint_algorithm(y, x - 1, map_p, aio);
	return (1);
}

void		ft_position(t_aio *aio)
{
	char	c;
	int		i;
	int		j;
	int		d;

	i = -1;
	d = 0;
	while (++i < aio->map.height)
	{
		j = -1;
		while (++j < aio->map.width)
		{
			c = aio->map.map[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				aio->plr.pos_y = (double)i + 0.5;
				aio->plr.pos_x = (double)j + 0.5;
				aio->plr.dir_x = (c == 'E' || c == 'W') ? 1 : 0;
				aio->plr.dir_x *= (c == 'W') ? -1 : 1;
				aio->plr.dir_y = (c == 'S' || c == 'N') ? 1 : 0;
				aio->plr.dir_y *= (c == 'N') ? -1 : 1;
				aio->parse_error.player++;
			}
		}
	}
}
