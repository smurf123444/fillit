/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:48:37 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 14:48:40 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_array(char **array)
{
	int index;

	index = 0;
	while (array[index] != NULL)
	{
		ft_putstr(array[index]);
		ft_putchar('\n');
		++index;
	}
}

void	ft_print_tetrimino(t_tet *tetrimino)
{
	int index;

	index = 0;
	while (index < 4)
	{
		ft_putnbr(tetrimino->x[index]);
		ft_putchar(' ');
		ft_putnbr(tetrimino->y[index]);
		ft_putchar('\n');
		++index;
	}
	ft_putchar('\n');
}
