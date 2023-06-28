/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:16:23 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/05 16:51:10 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_word_end(char const *s, char c, int start)
{
	int	count;

	count = 0;
	while (s[start] != c && s[start] != '\0')
	{
		count++;
		start++;
	}
	return (count);
}

static void	ft_fill_tab(char **tab, char const *s, char c)
{
	int	i;
	int	nb_word;
	int	start;
	int	end;

	i = 0;
	start = 0;
	nb_word = ft_word_count(s, c);
	while (i < nb_word)
	{
		while (s[start] == c)
			start++;
		end = ft_word_end(s, c, start);
		if (end != 0)
		{
			tab[i] = ft_substr(s, start, end);
			i++;
		}
		start += end;
	}
	tab[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_word;

	if (s == NULL)
		return (NULL);
	nb_word = ft_word_count(s, c);
	tab = ft_calloc((nb_word) + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	ft_fill_tab(tab, s, c);
	return (tab);
}
