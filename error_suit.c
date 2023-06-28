/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_suit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:39:04 by njegat            #+#    #+#             */
/*   Updated: 2023/01/12 18:25:49 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_empty(char **argv, int argc)
{
	int		i;
	size_t	j;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (ft_strlen(argv[i]) == 0 || j == ft_strlen(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_check_double(char **array)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (!array)
		return (array);
	while (array[i])
	{
		j = 0;
		tmp = ft_atoll(array[i]);
		while (array[j])
		{
			if (ft_atoll(array[j]) == tmp && i != j)
			{
				ft_putstr_fd("Error\n", 2);
				ft_double_free(array);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	ft_tab_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	i++;
	return (i);
}

char	**ft_symplify(char **array)
{
	int		i;
	int		j;
	int		index;
	char	**output;

	i = 0;
	if (!array)
		return (NULL);
	output = malloc(sizeof(char *) * (ft_tab_len(array) + 1));
	while (array[i])
	{
		j = 0;
		index = 0;
		while (array[j])
		{
			if (ft_atoll(array[j]) < ft_atoll(array[i]))
				index++;
			j++;
		}
		output[i] = ft_itoa(index);
		i++;
	}
	ft_double_free(array);
	output[i] = 0;
	return (output);
}
