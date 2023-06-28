/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:59:16 by njegat            #+#    #+#             */
/*   Updated: 2023/01/25 15:48:30 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *stack_a, char **instruction)
{
	if (stack_a->number > stack_a->next->number
		&& stack_a->next->number < stack_a->next->next->number
		&& stack_a->number > stack_a->next->next->number)
	{
		ft_rotate(stack_a, 'a', instruction);
		return ;
	}
	while (!ft_alreadysort(stack_a))
	{
		if (stack_a->number > stack_a->next->number)
			ft_swap(stack_a, 'a', instruction);
		else
			ft_reverse_rotate(stack_a, 'a', instruction);
	}
}

void	ft_sort_five(t_stack **stack_a, char **instruction)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	i = 0;
	while (i < 2)
	{
		ft_rotate_top(stack_a, i, 'a', instruction);
		ft_push(stack_a, &stack_b, 'b', instruction);
		i++;
	}
	ft_sort_three(*stack_a, instruction);
	ft_push(&stack_b, stack_a, 'a', instruction);
	ft_push(&stack_b, stack_a, 'a', instruction);
	ft_stackclear(&stack_b);
}
