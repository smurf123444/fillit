/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:15:59 by chmannin          #+#    #+#             */
/*   Updated: 2018/07/25 19:16:05 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;

	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	x = (char *)malloc((len + 1) * sizeof(char));
	if (x == NULL)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i] != '\0')
		x[i] = s[start + i];
	x[i] = '\0';
	return (x);
}
