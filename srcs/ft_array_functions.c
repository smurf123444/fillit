/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:35:09 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 14:35:24 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_new_array(int x, int y)
{
	char	**arr;
	int		index;
	int		jay;

	jay = 0;
	arr = (char**)malloc(sizeof(char*) * (y + 1));
	while (jay < y)
	{
		index = 0;
		arr[jay] = (char*)malloc(sizeof(char) * (x + 1));
		while (index < x)
		{
			arr[jay][index] = '.';
			index++;
		}
		arr[jay][index] = '\0';
		jay++;
	}
	arr[jay] = NULL;
	return (arr);
}

static int		ft_starting_size(char *tetrimino)
{
	int x;
	int area;
	int square;

	x = 0;
	square = 0;
	area = ((ft_strlen(tetrimino) + 1) / 21) * 4;
	while ((x++ * square++) < area)
		;
	return (x - 1);
}

t_map			*ft_starting_map(char *tetrimino)
{
	int		x;
	int		y;
	t_map	*map;

	x = ft_starting_size(tetrimino);
	y = x;
	map = (t_map*)malloc(sizeof(t_map));
	map->array = ft_new_array(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}

t_map			*ft_resize_map(t_map *old_map)
{
	int		x;
	int		y;
	t_map	*map;

	x = old_map->xmax + 1;
	y = old_map->ymax + 1;
	ft_free_map(old_map);
	map = (t_map*)malloc(sizeof(t_map));
	map->array = ft_new_array(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}
