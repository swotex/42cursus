/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:03:01 by njegat            #+#    #+#             */
/*   Updated: 2022/11/17 04:17:03 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*array;
	int		i;
	int		j;

	if (!(s1) || !(s2))
		return (NULL);
	array = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!(array))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		array[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		array[j] = s2[i];
		i++;
		j++;
	}
	array[j] = '\0';
	free(s1);
	return (array);
}
