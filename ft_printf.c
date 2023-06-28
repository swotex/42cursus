/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:02:47 by njegat            #+#    #+#             */
/*   Updated: 2022/11/01 12:30:53 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_manage_hexa(va_list param_info, char c)
{
	int				w_number;
	unsigned long	param_p;
	unsigned int	param_x;

	w_number = 1;
	if (c == 'p')
	{
		param_p = va_arg(param_info, unsigned long);
		if (!(param_p))
		{
			w_number = ft_putstr("(nil)");
			return (w_number);
		}
		ft_putstr("0x");
		w_number = ft_putnbr_base(param_p, "0123456789abcdef", w_number) + 2;
	}
	else if (c == 'x' || c == 'X')
	{
		param_x = va_arg(param_info, unsigned int);
		if (c == 'x')
			w_number = ft_putnbr_base(param_x, "0123456789abcdef", w_number);
		else if (c == 'X')
			w_number = ft_putnbr_base(param_x, "0123456789ABCDEF", w_number);
	}
	return (w_number);
}

int	ft_manage_characters(va_list param_info, char c)
{
	int	w_number;

	w_number = 0;
	if (c == 'c')
		w_number = ft_putchar(va_arg(param_info, int));
	else if (c == '%')
		w_number = ft_putchar('%');
	else if (c == 's')
		w_number = ft_putstr(va_arg(param_info, char *));
	return (w_number);
}

int	ft_manage_nbr(va_list param_info, char c)
{
	int	w_number;

	w_number = 0;
	if (c == 'i' || c == 'd')
		w_number = ft_putnbr(va_arg(param_info, int), 0);
	else if (c == 'u')
		w_number = ft_putnbr_unsigned(va_arg(param_info, unsigned int), 0);
	return (w_number);
}

int	ft_printf(const char *str, ...)
{
	va_list	param_info;
	int		w_number;

	w_number = 0;
	if (!str)
		return (-1);
	va_start(param_info, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'i' || *str == 'd' || *str == 'u')
				w_number += ft_manage_nbr(param_info, *str);
			else if (*str == 's' || *str == 'c' || *str == '%')
				w_number += ft_manage_characters(param_info, *str);
			else if (*str == 'x' || *str == 'X' || *str == 'p')
				w_number += ft_manage_hexa(param_info, *str);
		}
		else
			w_number += ft_putchar(*str);
		str++;
	}
	va_end(param_info);
	return (w_number);
}
void main()
{
	printf("%d", ft_printf("%%%"));
	printf("%d", printf("%%%"));
}
