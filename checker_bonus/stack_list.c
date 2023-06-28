/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:33:00 by njegat            #+#    #+#             */
/*   Updated: 2023/01/08 16:13:13 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_stacknew(int number)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->number = number;
	element->next = NULL;
	return (element);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_stacklast(*lst);
		tmp->next = new;
	}
}

void	ft_stackdelone(t_stack *lst)
{
	if (lst)
	{
		lst->number = 0;
		lst->next = NULL;
		free(lst);
	}
}

void	ft_stackclear(t_stack **lst)
{
	t_stack	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_stackdelone(*lst);
			*lst = tmp;
		}
	}
}
