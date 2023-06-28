/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:07:27 by njegat            #+#    #+#             */
/*   Updated: 2023/06/13 14:29:26 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_alpha(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == 0)
			return (1);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	size_int(char **argv)
{
	int			i;
	long long	tmp;

	i = 1;
	tmp = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 10)
			return (1);
		tmp = ft_atoll(argv[i]);
		if (tmp > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

static int	check_arg(char **argv)
{
	if (ft_atoi(argv[1]) == 0)
		return (1);
	if (ft_atoi(argv[2]) == 0)
		return (1);
	if (ft_atoi(argv[3]) == 0)
		return (1);
	if (ft_atoi(argv[4]) == 0)
		return (1);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) == 0)
			return (1);
	}
	return (0);
}

int	parsing_handler(int argc, char **argv)
{
	int	error;

	error = 0;
	if (argc < 5 || argc > 6)
	{
		printf("wrong number of argument\n");
		error = 1;
	}
	else if (check_alpha(argv))
	{
		printf("error\n");
		error = 1;
	}
	else if (size_int(argv))
	{
		printf("error\n");
		error = 1;
	}
	else if (check_arg(argv))
	{
		printf("error\n");
		error = 1;
	}
	return (error);
}
