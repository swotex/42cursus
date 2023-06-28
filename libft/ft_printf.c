/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:21:10 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/15 11:42:50 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_flag(char c, char *flags)
{
	int		i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_print_ptr_fd(unsigned long ptr, int fd)
{
	int	count;

	count = 0;
	if (ptr != 0)
	{
		count += ft_putstr_pf_fd("0x", fd);
		count += ft_putptr_pf_fd(ptr, fd);
	}
	else
		count += ft_putstr_pf_fd("(nil)", fd);
	return (count);
}

int	ft_launch_print(char c, va_list arg, int fd)
{
	int				count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_pf_fd(va_arg(arg, int), fd);
	if (c == 's')
		count += ft_putstr_pf_fd(va_arg(arg, char *), fd);
	if (c == 'i' || c == 'd')
		count += ft_putnbr_base_fd(va_arg(arg, int), "0123456789", fd);
	if (c == 'x')
		count += ft_putnbr_base_fd(va_arg(arg, unsigned int),
				"0123456789abcdef", fd);
	if (c == 'X')
		count += ft_putnbr_base_fd(va_arg(arg, unsigned int),
				"0123456789ABCDEF", fd);
	if (c == 'u')
		count += ft_putnbr_base_fd(va_arg(arg, unsigned int), "0123456789", fd);
	if (c == 'p')
		count += ft_print_ptr_fd(va_arg(arg, unsigned long), fd);
	if (c == '%')
		count += ft_putchar_pf_fd(c, fd);
	return (count);
}

int	ft_printf_fd(int fd, const char *s, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_check_flag(s[i + 1], "cspdiuxX%"))
		{
			i++;
			count += ft_launch_print(s[i], arg, fd);
		}
		else
			count += ft_putchar_pf_fd(s[i], fd);
		i++;
	}
	va_end(arg);
	return (count);
}
