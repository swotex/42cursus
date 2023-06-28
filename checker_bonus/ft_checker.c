/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:20:13 by njegat            #+#    #+#             */
/*   Updated: 2023/01/10 18:42:20 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_inst(char *inst)
{
	if (!ft_strncmp(inst, "sa\n", 3) || !ft_strncmp(inst, "sb\n", 3))
		return (0);
	if (!ft_strncmp(inst, "pa\n", 3) || !ft_strncmp(inst, "pb\n", 3))
		return (0);
	if (!ft_strncmp(inst, "ra\n", 3) || !ft_strncmp(inst, "rb\n", 3))
		return (0);
	if (!ft_strncmp(inst, "rra\n", 4) || !ft_strncmp(inst, "rrb\n", 4))
		return (0);
	if (!ft_strncmp(inst, "ss\n", 3) || !ft_strncmp(inst, "rr\n", 3))
		return (0);
	if (!ft_strncmp(inst, "rrr\n", 4))
		return (0);
	return (1);
}

void	ft_modif_stack_double(t_stack **stack_a, t_stack **stack_b, char *inst)
{
	if (!ft_strncmp(inst, "ss\n", 3))
	{
		ft_swap(*stack_a);
		ft_swap(*stack_b);
	}
	if (!ft_strncmp(inst, "rr\n", 3))
	{
		ft_rotate(*stack_a);
		ft_rotate(*stack_b);
	}
	if (!ft_strncmp(inst, "rrr\n", 4))
	{
		ft_reverse_rotate(*stack_a);
		ft_reverse_rotate(*stack_b);
	}
}

void	ft_modif_stack(t_stack **stack_a, t_stack **stack_b, char *inst)
{
	if (!ft_strncmp(inst, "sa\n", 3))
		ft_swap(*stack_a);
	if (!ft_strncmp(inst, "sb\n", 3))
		ft_swap(*stack_b);
	if (!ft_strncmp(inst, "pa\n", 3))
		ft_push(stack_b, stack_a);
	if (!ft_strncmp(inst, "pb\n", 3))
		ft_push(stack_a, stack_b);
	if (!ft_strncmp(inst, "ra\n", 3))
		ft_rotate(*stack_a);
	if (!ft_strncmp(inst, "rb\n", 3))
		ft_rotate(*stack_b);
	if (!ft_strncmp(inst, "rra\n", 4))
		ft_reverse_rotate(*stack_a);
	if (!ft_strncmp(inst, "rrb\n", 4))
		ft_reverse_rotate(*stack_b);
	ft_modif_stack_double(stack_a, stack_b, inst);
}

int	ft_check_command(t_stack **stack_a, t_stack **stack_b)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst)
	{
		if (ft_check_inst(inst))
		{
			ft_putstr_fd("Error\n", 1);
			ft_stackclear(stack_a);
			ft_stackclear(stack_b);
			free(inst);
			return (1);
		}
		ft_modif_stack(stack_a, stack_b, inst);
		free(inst);
		inst = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	array = ft_check_entry(argc, argv);
	if (!array)
		return (1);
	stack_a = ft_create_stack(array);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	if (ft_check_command(&stack_a, &stack_b))
		return (1);
	if (stack_b || !ft_alreadysort(stack_a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
}
