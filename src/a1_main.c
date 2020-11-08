/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a1_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:25:31 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 21:07:04 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int			main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (0);
	}
	while (argv[1][i] != '\0')
		i++;
	if (i > 4 && ft_strcmp(&argv[1][i - 4], ".cub") != 0)
		ft_putstr_fd("Error\nPS change to *.cub\n", 2);
	else if (i <= 4)
		ft_putstr_fd("Error\nPS change to *.cub\n", 2);
	else if (argc == 2)
		ft_cub(argv[1], 0);
	else if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			ft_cub(argv[1], 1);
		else
			ft_putstr_fd("Error\nTry --save\n", 2);
	}
	return (0);
}

int			ft_cub(char *cub, int screenshot)
{
	t_aio *aio;

	if (!(aio = (t_aio *)malloc(sizeof(t_aio))))
		return (ft_error_number(1));
	ft_initialization(aio);
	aio->mlx.ptr = mlx_init();
	mlx_get_screen_size(aio->mlx.ptr, &aio->res.display_x, &aio->res.display_y);
	ft_putstr_fd("YOUR DISPLAY RES = ", 1);
	ft_putnbr_fd(aio->res.display_x, 1);
	ft_putnbr_fd(aio->res.display_y, 1);
	ft_putstr_fd("\n*the program update the res\n\n", 1);
	if (ft_parse(aio, cub) == -1)
		return (ft_close(aio, 0));
	ft_init_img_and_win(aio);
	if (screenshot == 1)
		return (ft_bmp_save(aio));
	ft_main_put_image(aio);
	mlx_hook(aio->win.ptr, 2, 1L << 0, ft_press, aio);
	mlx_hook(aio->win.ptr, 3, 1L << 1, ft_release, aio);
	mlx_hook(aio->win.ptr, 17, 1L << 0, ft_close2, aio);
	mlx_loop_hook(aio->mlx.ptr, ft_key, aio);
	mlx_loop(aio->mlx.ptr);
	return (1);
}

void		ft_init_img_and_win(t_aio *aio)
{
	aio->win.ptr = mlx_new_window(aio->mlx.ptr, aio->res.map_x,
									aio->res.map_y, "cub3D");
	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->res.map_x, aio->res.map_y);
	aio->img.adr = (unsigned int *)mlx_get_data_addr(aio->img.ptr,
			&aio->img.bits_per_pixel, &aio->img.line_length, &aio->img.endian);
	ft_pre_put_image(aio);
	if (aio->res.map_x >= 300 && aio->res.map_y >= 300)
		aio->res.if_map = 1;
}
