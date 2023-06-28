/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:12:27 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/05 13:31:12 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_mod;
	t_list	*stock;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	stock = ft_lstnew((*f)(lst->content));
	if (stock == NULL)
		return (NULL);
	lst_mod = stock;
	lst = lst->next;
	while (lst)
	{
		stock = ft_lstnew((*f)(lst->content));
		if (stock == NULL)
		{
			ft_lstclear(&lst_mod, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_mod, stock);
		lst = lst->next;
	}
	return (lst_mod);
}
