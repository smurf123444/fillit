/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:12:50 by chmannin          #+#    #+#             */
/*   Updated: 2018/07/25 19:12:53 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	if (n == 0)
		return (1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
	{
		if ((s1[i + 1] == '\0' && s2[i + 1] == '\0') || i + 1 == n)
			return (1);
		i++;
	}
	return (0);
}
