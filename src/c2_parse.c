/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c2_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:58:26 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/07 20:14:55 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int			ft_parse_errors(t_aio *aio)
{
	ft_map_parse(aio);
	ft_position(aio);
	if (aio->parse_error.settings != 0)
		return (ft_error_number(aio->parse_error.settings));
	if (aio->res.map_x <= 0 || aio->res.map_y <= 0)
		return (ft_error_number(13));
	else if ((aio->tex.no == NULL || aio->tex.so == NULL || aio->tex.we == NULL)
			|| (aio->tex.ea == NULL || aio->tex.sp == NULL))
		return (ft_error_number(14));
	else if (aio->tex.ce == 0xFF000000 || aio->tex.fl == 0xFF000000)
		return (ft_error_number(15));
	else if (aio->parse_error.player == 0)
		return (ft_error_number(16));
	else if (aio->parse_error.player > 1)
		return (ft_error_number(17));
	else if (ft_walls(aio) == -1)
		return (ft_error_number(99));
	aio->map.height += 2;
	aio->map.width += 2;
	ft_slist(aio);
	return (1);
}

int			ft_map_parse(t_aio *aio)
{
	int		cut_left;
	int		cut_right;
	size_t	sizemem;

	aio->map.height = ft_lstsize(aio->map.list) - 1;
	sizemem = (aio->map.height + 1) * sizeof(char *);
	if (!(aio->map.map = (char **)malloc(sizemem)))
		return (-11);
	aio->map.map[aio->map.height] = NULL;
	return (ft_write_and_cut(aio, &cut_left, &cut_right));
}

int			ft_write_and_cut(t_aio *aio, int *cut_left, int *cut_right)
{
	int		i;
	t_list	*tmp;

	tmp = aio->map.list;
	i = 0;
	while (i < aio->map.height)
	{
		ft_write_and_cut_2(aio, tmp, i);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void		ft_write_and_cut_2(t_aio *aio, t_list *tmp, int i)
{
	int k;
	int j;

	k = 0;
	j = aio->map.cut_left;
	aio->map.map[i] = (char *)malloc(sizeof(char) * (aio->map.width + 1));
	aio->map.map[i][aio->map.width] = 0;
	while (((char *)tmp->content)[j] && j < aio->map.width + aio->map.cut_left)
	{
		if (ft_write_and_cut_check(((char *)tmp->content)[j]))
			aio->parse_error.settings = 18;
		else
			aio->map.map[i][k] = (((char *)tmp->content)[j]);
		if (((char *)tmp->content)[j] == '2')
			aio->map.sprite_count++;
		k++;
		j++;
	}
	while (k < aio->map.width)
	{
		aio->map.map[i][k] = ' ';
		k++;
	}
}

int			ft_write_and_cut_check(char check)
{
	if (check != '0' && check != '1' &&
		check != '2' &&
		check != 'N' && check != 'S' &&
		check != 'W' &&
		check != 'E' && check != ' ')
		return (1);
	return (0);
}
