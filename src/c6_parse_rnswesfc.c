/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c6_parse_rnswesfc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:02:04 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 21:27:51 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int		ft_resolution(t_aio *aio, char *line, int *i)
{
	if (aio->res.map_x != 0 || aio->res.map_y != 0)
		return (6);
	(*i)++;
	aio->res.map_x = ft_atoi_i(line, i);
	aio->res.map_y = ft_atoi_i(line, i);
	if (aio->res.map_x > aio->res.display_x)
		aio->res.map_x = aio->res.display_x;
	if (aio->res.map_y > aio->res.display_y)
		aio->res.map_y = aio->res.display_y;
	ft_skip_spases(line, i);
	if (aio->res.map_x <= 0 || aio->res.map_y <= 0 || line[*i] != '\0')
		return (7);
	return (0);
}

int		ft_texture(t_aio *aio, unsigned int **adr, char *line, int *i)
{
	int		fd;
	void	*img;
	int		tab[5];
	char	*texture;

	if (*adr != NULL)
		return (10);
	(*i) += 2;
	ft_skip_spases(line, i);
	texture = &line[*i];
	(*i) += ft_strlen(texture);
	if (ft_check_file_ext(texture, ".xpm") == 0)
		return (12);
	if ((fd = open(texture, O_RDONLY)) == -1)
		return (11);
	close(fd);
	img = mlx_xpm_file_to_image(aio->mlx.ptr, texture, &tab[0], &tab[1]);
	aio->res.tex = tab[0];
	if (img == NULL || tab[0] != TEX || tab[1] != TEX)
		return (12);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);
}

int		ft_rgb(unsigned int *color, char *line, int *i, t_aio *aio)
{
	int	r;
	int	g;
	int	b;

	if (*color != 0xFF000000)
		return (8);
	(*i)++;
	r = ft_atoi_i(line, i);
	ft_skip_spases(line, i);
	if (line[(*i)++] != ',')
		return (9);
	g = ft_atoi_i(line, i);
	ft_skip_spases(line, i);
	if (line[(*i)++] != ',')
		return (9);
	b = ft_atoi_i(line, i);
	ft_skip_spases(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (9);
	aio->tex.r = r;
	aio->tex.g = g;
	aio->tex.b = b;
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}
