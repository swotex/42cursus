/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:46:59 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/24 16:58:52 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int n)
{
	int	count;

	if (n < 0 || n == 0)
		count = 1;
	else
		count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_fillstr(char *str, long n, int len)
{
	int	i;

	i = 1;
	while (i <= len && n != 0)
	{
		str[len - i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	str[len] = '\0';
}

char	*ft_itoa(int n)
{
	int		len;
	long	long_n;
	char	*str;

	long_n = (long)n;
	len = ft_nblen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (long_n < 0)
	{
		str[0] = '-';
		long_n *= -1;
	}
	if (long_n == 0)
		str[0] = '0';
	ft_fillstr(str, long_n, len);
	return (str);
}
