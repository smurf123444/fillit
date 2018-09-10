/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:47:35 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:47:37 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *s;
	char *d;

	s = (char*)src;
	d = (char*)dst;
	while (n > 0 && *s != c)
	{
		--n;
		*d++ = *s++;
	}
	if (n > 0)
	{
		*d++ = c;
		return ((void*)d);
	}
	else
		return (NULL);
}
