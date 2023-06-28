/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:52:28 by njegat            #+#    #+#             */
/*   Updated: 2023/01/08 10:56:27 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addinstruction(char *new, char **instruction)
{
	if (*instruction && new)
	{
		*instruction = ft_strjoin(*instruction, " ");
		*instruction = ft_strjoin(*instruction, new);
	}
}

static int	ft_shorten(char *first, char *second)
{
	int	check;

	check = ft_atoll(first) + ft_atoll(second);
	if (check == 65)
		write(1, "ss", 2);
	else if (check == 72)
		write(1, "rr", 2);
	else if (check == 54)
		write(1, "rrr", 3);
	if (check == 65 || check == 72 || check == 54)
		return (1);
	return (0);
}

static void	ft_print_inst(char *inst)
{
	int	check;

	check = ft_atoll(inst);
	if (check == 37)
		write(1, "sa", 2);
	else if (check == 28)
		write(1, "sb", 2);
	else if (check == 43)
		write(1, "pa", 2);
	else if (check == 12)
		write(1, "pb", 2);
	else if (check == 64)
		write(1, "ra", 2);
	else if (check == 8)
		write(1, "rb", 2);
	else if (check == 23)
		write(1, "rra", 3);
	else if (check == 31)
		write(1, "rrb", 3);
}

void	ft_printall(char **instruction)
{
	char	**inst;
	int		i;
	int		check;

	inst = ft_split(*instruction, ' ');
	if (!inst)
		return ;
	i = 1;
	while (inst[i])
	{
		check = ft_shorten(inst[i], inst[i - 1]);
		if (check)
			i++;
		else
			ft_print_inst(inst[i - 1]);
		write(1, "\n", 1);
		i++;
	}
	ft_print_inst(inst[i - 1]);
	write(1, "\n", 1);
	ft_double_free(inst);
}
