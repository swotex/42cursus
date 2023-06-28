/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:03:01 by njegat            #+#    #+#             */
/*   Updated: 2023/01/17 15:05:24 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_linelen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_strfind(const char *s, int c)
{
	int		i;
	char	search;

	search = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == search)
			return (i);
		i--;
	}
	return (0);
}
