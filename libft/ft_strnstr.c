/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:48:17 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/09/28 18:59:23 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	tmp;

	j = 0;
	i = 0;
	if (big == 0 && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i <= len)
	{
		tmp = i;
		while (big[tmp] == little[j] && little[j] != '\0')
		{
			tmp++;
			j++;
			if (little[j] == '\0' && tmp <= len)
				return ((char *)&big[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
