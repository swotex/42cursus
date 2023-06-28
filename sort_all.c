/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:40:07 by njegat            #+#    #+#             */
/*   Updated: 2023/01/10 15:45:24 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_butterfly(t_stack **stk_a, t_stack **stk_b, int cut, char **inst)
{
	int	cut_max;
	int	j;
	int	stack_len;

	stack_len = ft_stacklen(*stk_a);
	cut_max = stack_len / cut;
	while (*stk_a)
	{
		j = 0;
		while (j < stack_len / cut && *stk_a)
		{
			if ((*stk_a)->number < cut_max)
			{
				ft_push(stk_a, stk_b, 'b', inst);
				if ((*stk_b)->number > (cut_max - (stack_len / (2 * cut))))
					ft_rotate(*stk_b, 'b', inst);
				j++;
			}
			else
				ft_rotate(*stk_a, 'a', inst);
		}
		cut_max += stack_len / cut;
	}
}

int	ft_smart_rotate(t_stack **stk_a, t_stack **stk_b, int nb, char **inst)
{
	int	pos;
	int	push;
	int	rotate_way;

	pos = ft_whereis_number(*stk_b, nb);
	push = 0;
	rotate_way = 1;
	if (ft_stacklen(*stk_b) < 2)
		return (0);
	if (pos > ft_stacklen(*stk_b) / 2)
		rotate_way = 2;
	while (pos != 1)
	{
		if ((*stk_b)->number == nb - 1)
		{
			ft_push(stk_b, stk_a, 'a', inst);
			push ++;
		}
		pos = ft_whereis_number(*stk_b, nb);
		if (pos != 1 && rotate_way == 1)
			ft_rotate(*stk_b, 'b', inst);
		else if (pos != 1 && rotate_way == 2)
			ft_reverse_rotate(*stk_b, 'b', inst);
	}
	return (push);
}

void	ft_secondsort(t_stack **stack_a, t_stack **stack_b, char **instruction)
{
	int	max;
	int	push;

	max = ft_whatis_max(*stack_b);
	ft_rotate_top(stack_b, max, 'b', instruction);
	ft_push(stack_b, stack_a, 'a', instruction);
	while (*stack_b)
	{
		push = 0;
		max = ft_whatis_max(*stack_b);
		push = ft_smart_rotate(stack_a, stack_b, max, instruction);
		if (push)
		{
			ft_push(stack_b, stack_a, 'a', instruction);
			ft_swap(*stack_a, 'a', instruction);
		}
		else
			ft_push(stack_b, stack_a, 'a', instruction);
	}
}

void	ft_sort_all(t_stack **stack_a, char **instruction)
{
	t_stack	*stack_b;
	int		stack_len;

	stack_b = NULL;
	stack_len = ft_stacklen(*stack_a);
	if (stack_len >= 400)
		ft_butterfly(stack_a, &stack_b, 9, instruction);
	else if (stack_len >= 300)
		ft_butterfly(stack_a, &stack_b, 6, instruction);
	else if (stack_len >= 200)
		ft_butterfly(stack_a, &stack_b, 5, instruction);
	else if (stack_len >= 100)
		ft_butterfly(stack_a, &stack_b, 4, instruction);
	else
		ft_butterfly(stack_a, &stack_b, 3, instruction);
	ft_secondsort(stack_a, &stack_b, instruction);
	ft_stackclear(&stack_b);
}
