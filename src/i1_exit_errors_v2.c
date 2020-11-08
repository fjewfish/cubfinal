/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i1_exit_errors_v2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:45:47 by fjewfish          #+#    #+#             */
/*   Updated: 2020/11/08 20:09:33 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header_v2.h"

int		ft_close(t_aio *aio, int win)
{
	if (win == 1)
	{
		mlx_destroy_window(aio->mlx.ptr, aio->win.ptr);
		ft_putstr_fd("NICE GAME\n", 1);
	}
	else
	{
		ft_putstr_fd("First render image save as ""screenshot.bmp""\n", 1);
	}
	exit(0);
	return (1);
}

int		ft_close2(t_aio *aio, int win)
{
	ft_putstr_fd("NICE GAME\n", 1);
	exit(0);
	return (1);
}

int		ft_error_number(int error)
{
	if (error == 1)
		ft_putstr_fd("Error\n1! Houston, we've have a problem MALLOC :(\n", 2);
	else if (error == 2)
		ft_putstr_fd("Error\n2! FD, Houston, we couldn't open file :(\n", 2);
	else if (error == 3)
		ft_putstr_fd("Error\n3! Houston, we have invalid map :(\n", 2);
	else if (error == 4)
		ft_putstr_fd("Error\n4! Houston, GNL fail :(\n", 2);
	else if (error == 5)
		ft_putstr_fd("Error\n5! Houston, Invalid line in file :(\n", 2);
	else if (error == 6)
		ft_putstr_fd("Error\n6! Houston, resolution re-specified :(\n", 2);
	else if (error == 7)
		ft_putstr_fd("Error\n7! Houston, resolution < 0 :(\n", 2);
	else if (error == 8)
		ft_putstr_fd("Error\n8! Houston, floor/ceiling re-specified :(\n", 2);
	else if (error == 9)
		ft_putstr_fd("Error\n9! Houston, problem floor/ceiling line :(\n", 2);
	else
		ft_error_number_2(error);
	return (-1);
}

void	ft_error_number_2(int error)
{
	if (error == 10)
		ft_putstr_fd("Error\n10! Houston, texture re-specified :(\n", 2);
	else if (error == 11)
		ft_putstr_fd("Error\n11! Houston, couldn't open texture file :(\n", 2);
	else if (error == 12)
		ft_putstr_fd("Error\n12! Houston, Invalid texture file :(\n", 2);
	else if (error == 13)
		ft_putstr_fd("Error\n13! Houston, no resolution :(\n", 2);
	else if (error == 14)
		ft_putstr_fd("Error\n14! Houston, no texture :(\n", 2);
	else if (error == 15)
		ft_putstr_fd("Error\n15! Houston, no floor/ceiling color :(\n", 2);
	else if (error == 16)
		ft_putstr_fd("Error\n16! Houston, no player position :(\n", 2);
	else if (error == 17)
		ft_putstr_fd("Error\n17! Houston, multiple positions :(\n", 2);
	else if (error == 99)
		ft_putstr_fd("Error\n99! Houston, where is the F##KING WALLS? :(\n", 2);
	else if (error == 19)
		ft_putstr_fd("Error\n19! Houston, not valid sybmol at map :(\n", 2);
}
