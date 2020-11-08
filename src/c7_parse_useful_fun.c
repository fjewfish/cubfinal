/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c7_parse_useful_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:02:08 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 14:07:26 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

void	ft_print_map_p(char **map_p)
{
	int i;

	i = 0;
	ft_putstr_fd("MAP.WALLS\n", 1);
	while (map_p[i])
	{
		ft_putstr_fd(map_p[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

int		ft_skip_spases(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int		ft_atoi_i(char *line, int *i)
{
	int	num;

	num = 0;
	ft_skip_spases(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}

int		ft_check_file_ext(char *file, char *ext)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	if (i > ft_strlen(ext) && ft_strcmp(&file[i - 4], ext) != 0)
		return (0);
	else if (i <= ft_strlen(ext))
		return (0);
	return (1);
}

int		free_map(char **map_p)
{
	int i;

	i = -1;
	ft_print_map_p(map_p);
	while (map_p[++i])
		free(map_p[i]);
	free(map_p);
	return (1);
}
