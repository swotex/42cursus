/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:41:33 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/02/15 16:49:05 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_string(char **tab, int first, int second)
{
	char	*tmp;

	if (!tab[first] || !tab[second])
		return ;
	tmp = ft_strdup(tab[first]);
	free(tab[first]);
	tab[first] = ft_strdup(tab[second]);
	free(tab[second]);
	tab[second] = ft_strdup(tmp);
	free(tmp);
}
