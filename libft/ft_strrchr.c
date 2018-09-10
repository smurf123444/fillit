/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:57:52 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:57:54 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
	}
	return (NULL);
}
