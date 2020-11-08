/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c4_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:07:44 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 14:12:42 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int			ft_walls(t_aio *aio)
{
	char	**map_p;
	char	**tmp;
	int		i;

	map_p = ft_init_protected_map(aio, '9');
	ft_recursive_while(map_p, aio);
	tmp = aio->map.map;
	aio->map.map = ft_init_protected_map(aio, '1');
	aio->plr.pos_x++;
	aio->plr.pos_y++;
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (ft_check_map_potected(map_p, aio));
}

char		**ft_init_protected_map(t_aio *aio, char change)
{
	char	**map_p;
	int		i;
	int		j;

	map_p = ft_init_protected_map_2(aio, change);
	i = 0;
	while (i < aio->map.height)
	{
		j = 0;
		map_p[i + 1] = (char *)malloc((aio->map.width + 3) * sizeof(char));
		map_p[i + 1][0] = change;
		map_p[i + 1][aio->map.width + 1] = change;
		map_p[i + 1][aio->map.width + 2] = 0;
		while (j < aio->map.width)
		{
			map_p[i + 1][j + 1] = aio->map.map[i][j];
			if (change == '9' && (map_p[i + 1][j + 1] == '2' ||
				map_p[i + 1][j + 1] == 'N' || map_p[i + 1][j + 1] == 'S' ||
				map_p[i + 1][j + 1] == 'E' || map_p[i + 1][j + 1] == 'W'))
				map_p[i + 1][j + 1] = '0';
			j++;
		}
		i++;
	}
	return (map_p);
}

char		**ft_init_protected_map_2(t_aio *aio, char change)
{
	char	**map_p;
	int		i;

	i = 0;
	map_p = (char **)malloc((aio->map.height + 3) * sizeof(char *) + 1);
	map_p[aio->map.height + 2] = NULL;
	map_p[0] = (char *)malloc((aio->map.width + 3) * sizeof(char));
	while (i < (aio->map.width + 2))
	{
		map_p[0][i] = change;
		i++;
	}
	map_p[0][i] = '\0';
	i = 0;
	map_p[aio->map.height + 1] = (char *)malloc((aio->map.width + 3));
	while (i < (aio->map.width + 2))
	{
		map_p[aio->map.height + 1][i] = change;
		i++;
	}
	map_p[aio->map.height + 1][i] = '\0';
	return (map_p);
}

int			ft_final_check(char check)
{
	if (check != '*' && check != '1' &&
		check != '2' &&
		check != ' ' && check != '9')
		return (1);
	return (0);
}

int			ft_check_map_potected(char **map_p, t_aio *aio)
{
	int		i;
	int		j;

	i = -1;
	while (map_p[++i])
	{
		j = -1;
		while (map_p[i][++j])
		{
			if (map_p[i][j] == '9')
			{
				if (i + 1 <= aio->map.height && map_p[i + 1][j] == '*')
					return (-1);
				if (i - 1 > 0 && map_p[i - 1][j] == '*')
					return (-1);
				if (j + 1 <= aio->map.width && map_p[i][j + 1] == '*')
					return (-1);
				if (j - 1 > 0 && map_p[i][j - 1] == '*')
					return (-1);
			}
			if (ft_final_check(map_p[i][j]))
				return (-1);
		}
	}
	return (free_map(map_p));
}
