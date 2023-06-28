/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:39:08 by njegat            #+#    #+#             */
/*   Updated: 2023/01/08 12:33:08 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	**ft_standardization(int argc, char **argv)
{
	char	*tmp;
	char	*tmp_two;
	char	**out;
	int		i;

	tmp = malloc(1);
	if (tmp)
		tmp[0] = '\0';
	i = 1;
	while (i < argc)
	{
		tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, argv[i]);
		i++;
	}
	tmp_two = ft_strtrim(tmp, " ");
	out = ft_split(tmp_two, ' ');
	if (tmp)
		free(tmp);
	if (tmp_two)
		free(tmp_two);
	if (!out)
		ft_putstr_fd("Error\n", 1);
	return (out);
}

static int	ft_char_allowed(char *str, int i)
{
	if (!ft_isdigit(str[i]))
	{
		if (str[i] != '-' && str[i] != '+')
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		else if (i > 0 || ft_strlen(str) == 1)
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
	}
	return (1);
}

static char	**ft_char_check(char **array)
{
	int	i;
	int	j;

	i = 0;
	if (!array)
		return (NULL);
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!ft_char_allowed(array[i], j))
			{
				ft_double_free(array);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (array);
}

static char	**ft_int_check(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (NULL);
	while (array[i])
	{
		if (ft_atoll(array[i]) > INT_MAX || ft_atoll(array[i]) < INT_MIN)
		{
			ft_putstr_fd("Error\n", 1);
			ft_double_free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

char	**ft_check_entry(int argc, char **argv)
{
	char	**array;

	if (ft_check_empty(argv, argc) == 0)
		return (NULL);
	array = ft_standardization(argc, argv);
	array = ft_char_check(array);
	array = ft_int_check(array);
	array = ft_check_double(array);
	array = ft_symplify(array);
	return (array);
}
