/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:31:34 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/02/15 18:30:58 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_tab(char **tab)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
