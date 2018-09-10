/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:56:14 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:56:15 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 && n-- > 0)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
