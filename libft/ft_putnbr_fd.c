/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:51:05 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:51:09 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long s;

	s = (long)n;
	if (s < 0)
	{
		ft_putchar_fd('-', fd);
		s = -s;
	}
	if (s >= 10)
	{
		ft_putnbr_fd((s / 10), fd);
		ft_putnbr_fd((s % 10), fd);
	}
	else
		ft_putchar_fd((s + '0'), fd);
}
