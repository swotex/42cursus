/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:52:32 by njegat            #+#    #+#             */
/*   Updated: 2023/01/10 15:02:47 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_sort(t_stack **stack_a)
{
	int		size_stack;
	char	*instruction;

	size_stack = ft_stacklen(*stack_a);
	instruction = malloc(1);
	if (instruction)
		instruction[0] = 0;
	else
	{
		ft_stackclear(stack_a);
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	if (size_stack == 2)
		ft_swap(*stack_a, 'a', &instruction);
	else if (size_stack == 3)
		ft_sort_three(*stack_a, &instruction);
	else if (size_stack == 5)
		ft_sort_five(stack_a, &instruction);
	else
		ft_sort_all(stack_a, &instruction);
	ft_printall(&instruction);
	if (instruction)
		free(instruction);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**array;
	t_stack	*stack_a;

	array = ft_check_entry(argc, argv);
	if (!array)
		return (1);
	stack_a = ft_create_stack(array);
	if (!stack_a)
		return (1);
	if (ft_alreadysort(stack_a))
	{
		ft_stackclear(&stack_a);
		return (0);
	}
	if (ft_sort(&stack_a))
		return (1);
	ft_stackclear(&stack_a);
	return (0);
}
