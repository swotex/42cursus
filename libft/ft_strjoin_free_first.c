/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_first.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:34:30 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/02/23 16:40:09 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_first(char *s1, char *s2)
{
	char	*str;
	int		size;

	if (!s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (s1)
	{
		ft_strlcat(str, s1, ft_strlen(s1) + 1);
		free(s1);
		s1 = NULL;
	}
	ft_strlcat(str, s2, size);
	return (str);
}
