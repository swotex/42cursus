/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:59:27 by njegat            #+#    #+#             */
/*   Updated: 2023/01/08 11:02:27 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack_swap, int target, char **instruction)
{
	t_stack	*tmp;
	int		swap;

	if (stack_swap && stack_swap->next)
	{
		tmp = stack_swap->next;
		swap = stack_swap->number;
		stack_swap->number = tmp->number;
		tmp->number = swap;
		if (target == 'a')
			ft_addinstruction("37", instruction);
		else if (target == 'b')
			ft_addinstruction("28", instruction);
	}
}

void	ft_rotate(t_stack *stack_rotate, int target, char **instruction)
{
	t_stack	*tmp;
	int		save;

	if (ft_stacklen(stack_rotate) < 2)
		return ;
	tmp = stack_rotate;
	save = tmp->number;
	while (tmp->next)
	{
		tmp->number = tmp->next->number;
		tmp = tmp->next;
	}
	tmp->number = save;
	if (target == 'a')
		ft_addinstruction("64", instruction);
	else if (target == 'b')
		ft_addinstruction("8", instruction);
}

void	ft_reverse_rotate(t_stack *stack_rrotate, int target, char **inst)
{
	t_stack	*tmp;
	int		save;
	int		num_save;

	if (ft_stacklen(stack_rrotate) < 2)
		return ;
	tmp = stack_rrotate;
	num_save = tmp->next->number;
	tmp->next->number = tmp->number;
	tmp = tmp->next;
	while (tmp->next)
	{
		save = num_save;
		num_save = tmp->next->number;
		tmp->next->number = save;
		tmp = tmp->next;
	}
	stack_rrotate->number = num_save;
	if (target == 'a')
		ft_addinstruction("23", inst);
	else if (target == 'b')
		ft_addinstruction("31", inst);
}

void	ft_push(t_stack **stack_s, t_stack **stack_c, int target, char **inst)
{
	t_stack	*tmp;

	if (!*stack_s)
		return ;
	tmp = *stack_c;
	*stack_c = *stack_s;
	*stack_s = (*stack_s)->next;
	(*stack_c)->next = tmp;
	if (target == 'a')
		ft_addinstruction("43", inst);
	else if (target == 'b')
		ft_addinstruction("12", inst);
}
