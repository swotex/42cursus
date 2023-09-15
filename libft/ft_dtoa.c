/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:46:59 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/26 02:38:44 by tdhaussy         ###   ########.fr       */
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

static void	ft_fillstr(char *str, int n, int len)
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

static void	add_decimal(char *str, double d, int decimal)
{
	int	i;

	i = 1;
	while (i <= decimal && d != 0)
	{
		d = (d - (int)d) * 10;
		str[i] = (int)d + 48;
		i++;
	}
	str[i] = '\0';
}

char	*ft_dtoa(double d, int decimal)
{
	int		len;
	char	*str;

	len = ft_nblen((int)d);
	str = malloc(sizeof(char) * (len + 2 + decimal));
	if (str == NULL)
		return (NULL);
	if (d < 0)
	{
		str[0] = '-';
		d *= -1;
	}
	if (d == 0)
		str[0] = '0';
	ft_fillstr(str, d, len);
	if (decimal <= 0 && d == (int)d)
		return (str);
	str[len] = '.';
	add_decimal(&str[len], d, decimal);
	return (str);
}
