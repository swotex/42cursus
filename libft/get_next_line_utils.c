/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:54:17 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/05 14:11:32 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_find_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_realloc_stock(char *s)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0' || s[i + 1] == '\0')
	{
		gnl_free_one(&s);
		return (NULL);
	}
	i++;
	new_str = malloc(sizeof(char) * (ft_strlen(&s[i]) + 1));
	if (!new_str)
	{
		gnl_free_all(&s, &new_str);
		return (NULL);
	}
	new_str[0] = '\0';
	ft_strlcat(new_str, &s[i], ft_strlen(&s[i]) + 1);
	free(s);
	s = NULL;
	return (new_str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	if (!s2)
		return (NULL);
	while (s2[i] && s2[i] != '\n')
		i++;
	size = ft_strlen(s1) + i + 1;
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (s1)
	{
		ft_strlcat(str, s1, ft_strlen(s1) + 1);
		free(s1);
		s1 = NULL;
	}
	ft_strlcat(str, s2, size);
	return (str);
}
