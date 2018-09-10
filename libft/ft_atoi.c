/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:42:46 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:42:48 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int sum;
	int negative;

	negative = 0;
	sum = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negative = 1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		sum *= 10;
		sum += (*str - '0');
		++str;
	}
	if (negative == 1)
		return (-sum);
	else
		return (sum);
}
