/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:59:03 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:59:04 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = 0;
	while (len && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		len--;
		i++;
	}
	trim = (char*)malloc(sizeof(char) * (len + 1));
	if (trim == NULL)
		return (NULL);
	s += i;
	i = 0;
	while (len--)
		trim[i++] = *s++;
	trim[i] = '\0';
	return (trim);
}
