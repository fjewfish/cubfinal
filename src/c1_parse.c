/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:58:17 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/31 19:07:36 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int			ft_parse(t_aio *aio, char *cub)
{
	char	*line;
	int		fd;
	int		err;
	int		i;

	err = 1;
	i = 0;
	fd = open(cub, O_RDONLY);
	if (fd == -1 && aio->parse_error.settings == 0)
		return (ft_error_number(2));
	while (err == 1 && aio->parse_error.settings == 0)
	{
		if ((err = get_next_line(fd, &line)) == 1)
			ft_gnl_parse(aio, line);
		if (err != 0)
			free(line);
	}
	close(fd);
	ft_lstadd_back(&aio->map.list, ft_lstnew((void *)ft_strdup(line)));
	free(line);
	if (err == -1)
		return (ft_error_number(4));
	if (aio->parse_error.settings != 0)
		return (ft_error_number(aio->parse_error.settings));
	return (ft_parse_errors(aio));
}

void		ft_gnl_parse(t_aio *aio, char *line)
{
	if (aio->parse_error.map_trigger == 0)
		ft_rnswesfc(aio, line);
	if (aio->parse_error.map_trigger == 1)
	{
		if (ft_skip_only_space_zero_up(line) &&
			aio->parse_error.map_empty_line == 0)
			aio->parse_error.map_empty_line = 1;
		if (aio->parse_error.map_empty_line == 1 &&
			ft_skip_only_space_zero_up(line))
			ft_makemap_list(aio, ft_strdup(line));
		else if (aio->parse_error.map_empty_line == 1)
			aio->parse_error.map_trigger = -1;
	}
	if (aio->parse_error.map_trigger == -1 &&
		ft_skip_only_space_zero_up(line))
		aio->parse_error.settings = 3;
}

void		ft_rnswesfc(t_aio *aio, char *line)
{
	int		i;

	i = 0;
	ft_skip_spases(line, &i);
	ft_rnswesfc_2(aio, line, &i);
	if (aio->parse_error.settings == 0 && line[i] != '\0'
		&& aio->parse_error.map_trigger != 1)
		aio->parse_error.settings = 5;
}

void		ft_rnswesfc_2(t_aio *aio, char *line, int *i)
{
	if (line[*i] == 'R' && line[*i + 1] == ' ')
		aio->parse_error.settings = ft_resolution(aio, line, i);
	else if (line[*i] == 'N' && line[*i + 1] == 'O' && line[*i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.no, line,
			i);
	else if (line[*i] == 'S' && line[*i + 1] == 'O' && line[*i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.so, line,
			i);
	else if (line[*i] == 'W' && line[*i + 1] == 'E' && line[*i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.we, line,
			i);
	else if (line[*i] == 'E' && line[*i + 1] == 'A' && line[*i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.ea, line,
			i);
	else if (line[*i] == 'S' && line[*i + 1] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.sp, line,
			i);
	else if (line[*i] == 'F' && line[*i + 1] == ' ')
		aio->parse_error.settings = ft_rgb(&aio->tex.fl, line, i, aio);
	else if (line[*i] == 'C' && line[*i + 1] == ' ')
		aio->parse_error.settings = ft_rgb(&aio->tex.ce, line, i, aio);
	else if (line[*i] != '\0')
		aio->parse_error.map_trigger = 1;
}

void		ft_makemap_list(t_aio *aio, char *line)
{
	int		i;
	int		left;
	int		width;
	int		len;
	t_list	*tmp;

	i = 0;
	len = ft_strlen(line);
	left = ft_skip_only_space_zero_left(line);
	width = len - ft_skip_only_space_zero_right(line) - left;
	if ((tmp = ft_lstnew((void *)line)) == NULL)
		aio->parse_error.settings = 1;
	else if (!aio->map.list)
	{
		aio->map.cut_left = left;
		aio->map.width = width;
		aio->map.list = tmp;
	}
	else
		ft_lstadd_back(&aio->map.list, tmp);
	if (left < aio->map.cut_left)
		aio->map.cut_left = left;
	if (width > aio->map.width)
		aio->map.width = width;
}
