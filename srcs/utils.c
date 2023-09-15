/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:36:30 by njegat            #+#    #+#             */
/*   Updated: 2023/07/25 18:45:21 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_set(char *str, char *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				count++;
			j++;
		}
		if (count == i)
			break ;
		else
			i++;
	}
	return (count);
}

char	**ft_strappend(char *add, char **in)
{
	char	**new_tab;
	int		i;

	if (in == NULL)
	{
		new_tab = ft_calloc(2, sizeof(char *));
		new_tab[0] = ft_strdup(add);
		return (new_tab);
	}
	i = 0;
	while (in[i] != NULL)
		i++;
	new_tab = ft_calloc(i + 2, sizeof(char *));
	i = 0;
	while (in[i] != NULL)
	{
		new_tab[i] = in[i];
		i++;
	}
	new_tab[i] = ft_strdup(add);
	new_tab[i + 1] = NULL;
	free(in);
	return (new_tab);
}
