/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:07:26 by chmannin          #+#    #+#             */
/*   Updated: 2018/07/25 19:07:29 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *x;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (x == NULL)
		return (NULL);
	x = ft_strcpy(x, s1);
	x = ft_strcat(x, s2);
	return (x);
}
