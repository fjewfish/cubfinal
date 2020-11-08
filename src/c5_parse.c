/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c5_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:14:13 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/07 20:09:43 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int			ft_skip_only_space_zero_up(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '0')
		i++;
	if (line[i] == '\0')
		return (0);
	return (1);
}

int			ft_skip_only_space_zero_left(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

int			ft_skip_only_space_zero_right(char *line)
{
	int i;
	int len;

	len = ft_strlen(line);
	i = len - 1;
	while (line[i] == ' ')
		i--;
	return (len - i - 1);
}
