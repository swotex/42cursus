/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:24:05 by njegat            #+#    #+#             */
/*   Updated: 2022/11/01 12:22:34 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
		return (i);
	}
	ft_putstr("(null)");
	return (6);
}

int	ft_putnbr(int nbr, int w_number)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (nbr < 0 && nbr >= -2147483647)
	{
		nbr *= -1;
		w_number += ft_putchar('-');
	}
	if (nbr > 9)
		w_number = ft_putnbr(nbr / 10, w_number);
	nbr = (nbr % 10) + '0';
	w_number += ft_putchar(nbr);
	return (w_number);
}

int	ft_putnbr_unsigned(unsigned int nbr, int w_number)
{
	if (nbr > 9)
		w_number = ft_putnbr_unsigned(nbr / 10, w_number);
	nbr = (nbr % 10) + '0';
	w_number += ft_putchar(nbr);
	return (w_number);
}

int	ft_putnbr_base(unsigned long nbr, char *base, int w_number)
{
	if (nbr < 16)
	{
		w_number = ft_putchar(base[nbr]);
		return (w_number);
	}
	w_number += ft_putnbr_base((nbr / 16), base, w_number);
	if (w_number)
	{
		ft_putchar(base[nbr % 16]);
		return (w_number);
	}
	return (0);
}
