/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:57:33 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:57:35 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		i;

	if (*little == '\0')
		return ((char*)big);
	while (*big && len > 0)
	{
		b = big;
		l = little;
		i = len;
		while (*l && *b == *l && i--)
		{
			l++;
			b++;
		}
		if (*l == '\0')
			return ((char*)big);
		big++;
		--len;
	}
	return (NULL);
}
