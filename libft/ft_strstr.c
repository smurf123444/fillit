/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:58:32 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:58:35 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *b;
	const char *l;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		b = big;
		l = little;
		while (*l && *b == *l)
		{
			l++;
			b++;
		}
		if (*l == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
