/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:47:52 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:47:55 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char*)str)[i] == (unsigned char)c)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
