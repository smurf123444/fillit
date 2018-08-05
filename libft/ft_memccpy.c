/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:48:27 by chmannin          #+#    #+#             */
/*   Updated: 2018/07/25 18:48:29 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
				const void *restrict src, int c, size_t n)
{
	char	*d;
	char	*s;
	char	x;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	x = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		d[i] = s[i];
		if (s[i] == x)
			return (dst + i + 1);
	}
	return (NULL);
}
