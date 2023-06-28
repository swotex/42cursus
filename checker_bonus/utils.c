/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:09:19 by njegat            #+#    #+#             */
/*   Updated: 2023/01/08 16:14:04 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_alreadysort(t_stack *stack_sort)
{
	t_stack	*tmp;
	t_stack	*current;

	if (ft_stacklen(stack_sort) == 1)
		return (1);
	current = stack_sort;
	tmp = current->next;
	while (tmp->next)
	{
		if (current->number > tmp->number)
		{
			return (0);
		}
		current = current->next;
		tmp = tmp->next;
	}
	if (current->number > tmp->number)
	{
		return (0);
	}
	return (1);
}

t_stack	*ft_create_stack(char **array)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*tmp;

	i = 1;
	stack_a = ft_stacknew(ft_atoll(array[0]));
	if (!stack_a)
		return (NULL);
	while (array[i])
	{
		tmp = ft_stacknew(ft_atoll(array[i]));
		if (!tmp)
		{
			ft_stackclear(&stack_a);
			ft_double_free(array);
			ft_putstr_fd("Error\n", 1);
			return (NULL);
		}
		ft_stackadd_back(&stack_a, tmp);
		i++;
	}
	ft_double_free(array);
	return (stack_a);
}

void	ft_double_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

int	ft_stacklen(t_stack *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
