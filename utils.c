/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:09:19 by njegat            #+#    #+#             */
/*   Updated: 2023/01/08 14:17:40 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_whereis_number(t_stack *stack_rch, int number)
{
	t_stack	*tmp;
	int		i;

	tmp = stack_rch;
	i = 1;
	while (tmp->number != number && tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_rotate_top(t_stack **stack_r, int number, int target, char **inst)
{
	int	pos;
	int	stack_len;

	stack_len = ft_stacklen(*stack_r);
	pos = ft_whereis_number(*stack_r, number);
	if (stack_len < 2)
		return ;
	if (pos <= stack_len / 2)
	{
		while (pos > 1)
		{
			ft_rotate(*stack_r, target, inst);
			pos--;
		}
	}
	else if (pos > stack_len / 2)
	{
		while (pos <= stack_len)
		{
			ft_reverse_rotate(*stack_r, target, inst);
			pos++;
		}
	}
}

int	ft_whatis_max(t_stack *stack_rch)
{
	int	nb_max;

	nb_max = stack_rch->number;
	while (stack_rch)
	{
		if (stack_rch->number > nb_max)
			nb_max = stack_rch->number;
		stack_rch = stack_rch->next;
	}
	return (nb_max);
}
