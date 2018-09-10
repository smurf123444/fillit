/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:55:27 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:55:29 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*mapped;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	mapped = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapped == NULL)
		return (NULL);
	while (s[i])
	{
		mapped[i] = f(s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
