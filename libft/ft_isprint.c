/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:44:29 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:44:32 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	char *characters;

	characters = " !\"#$%&\'()*+,-./:;<=>\?@[\\]^_`{|}~";
	if (ft_isalnum(c))
		return (1);
	while (*characters && *characters != c)
		++characters;
	if (*characters == '\0')
		return (0);
	else
		return (1);
}
