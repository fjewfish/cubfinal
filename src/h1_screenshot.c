/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h1_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:49:13 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 22:33:50 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

void				ft_bdata(t_aio *aio, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];
	unsigned int	*adr;
	int				k;

	adr = aio->img.adr;
	i = (aio->res.map_x) * (aio->res.map_y - 1);
	k = ((aio->res.map_x) * (aio->res.map_y - 1)) / (aio->res.map_x);
	while (i >= 0)
	{
		j = 0;
		while (j < aio->res.map_x)
		{
			buffer[0] = (unsigned char)(adr[i + COEF * k] % 256);
			buffer[1] = (unsigned char)(adr[i + COEF * k] / 256 % 256);
			buffer[2] = (unsigned char)(adr[i + COEF * k] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		k--;
		i -= 2 * aio->res.map_x;
	}
}

void				ft_binfo(t_aio *aio, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = aio->res.map_x;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = aio->res.map_y;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void				ft_bfile(t_aio *aio, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = aio->res.map_x * aio->res.map_y * 3;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

int					ft_bmp_save(t_aio *aio)
{
	int				fd;

	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->res.map_x, aio->res.map_y);
	aio->img.adr = (unsigned int *)mlx_get_data_addr(aio->img.ptr,
			&aio->img.bits_per_pixel, &aio->img.line_length, &aio->img.endian);
	if (aio->img.coef_dylib == 0)
		aio->img.coef_dylib = aio->img.line_length / 4 - aio->res.map_x;
	ft_create_img(aio);
	ft_map_mini(aio);
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bfile(aio, fd);
	ft_binfo(aio, fd);
	ft_bdata(aio, fd);
	close(fd);
	ft_close(aio, 0);
	return (1);
}
