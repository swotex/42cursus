/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:13:59 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/09/29 20:59:53 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_start_trim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	ft_get_end_trim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = ft_strlen(s1) - 1;
	j = 0;
	count = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i--;
			count++;
			j = 0;
		}
		else
			j++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size;
	size_t	start_trim;
	size_t	end_trim;

	start_trim = 0;
	end_trim = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start_trim = ft_get_start_trim(s1, set);
	if (start_trim == ft_strlen(s1))
		return (ft_strdup(""));
	end_trim = ft_get_end_trim(s1, set);
	size = ft_strlen(s1) - (start_trim + end_trim);
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[start_trim], size + 1);
	return (str);
}
