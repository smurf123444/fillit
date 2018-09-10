/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:52:49 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:52:51 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *cmp1;
	unsigned char *cmp2;

	cmp1 = (unsigned char*)s1;
	cmp2 = (unsigned char*)s2;
	while (*cmp1 == *cmp2 && *cmp1 && *cmp2)
	{
		++cmp1;
		++cmp2;
	}
	return (*cmp1 - *cmp2);
}
