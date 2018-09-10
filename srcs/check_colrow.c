/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:34:05 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 14:34:24 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tet_one(char *str, int i)
{
	int		col;
	int		row;

	while (str[i] != '\0')
	{
		row = 1;
		while (row < 5)
		{
			col = 1;
			while (str[i] != '\n')
			{
				col++;
				i++;
			}
			if (col != 5)
				return (1);
			row++;
			i++;
		}
		if (str[i] != '\0')
			return (1);
	}
	return (0);
}

static int	tet_multiple(char *str, int tet)
{
	int		i;
	int		col;
	int		row;

	i = -1;
	while (tet-- != 1 && str[++i] != '\0')
	{
		row = 0;
		while (++row < 5)
		{
			col = 1;
			while (str[i] != '\n' && col++ >= 0)
				i++;
			if (col != 5)
				return (1);
			i++;
		}
		if ((row == 5) && (str[i] != '\n'))
			return (1);
	}
	if (tet == 1 & str[i] != '\0')
		tet_one(str, i);
	return (0);
}

int			check_colrow(char *str, int tet)
{
	int val;

	if (tet == 1)
		val = tet_one(str, 0);
	if (tet > 1)
		val = tet_multiple(str, tet);
	if (val)
		return (1);
	else
		return (0);
}
