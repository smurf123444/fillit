/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:50:25 by chmannin          #+#    #+#             */
/*   Updated: 2018/07/25 18:50:28 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*s;
	char	*x;
	size_t	i;

	s = (char *)dst;
	x = (char *)src;
	i = -1;
	while (++i < n)
		s[i] = x[i];
	return (dst);
}
