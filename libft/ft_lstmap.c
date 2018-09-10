/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:46:38 by chmannin          #+#    #+#             */
/*   Updated: 2018/09/09 15:46:40 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;
	t_list *ret;

	ret = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!ret)
		{
			ret = tmp;
			new = ret;
			ret->next = NULL;
		}
		else
		{
			ret->next = tmp;
			tmp->next = NULL;
			ret = ret->next;
		}
		lst = lst->next;
	}
	return (new);
}
