/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:29:19 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/15 11:45:16 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_baselen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_base_fd(long n, char *base, int fd)
{
	int	base_lengh;
	int	last_nb;
	int	count;

	count = 0;
	base_lengh = ft_baselen(base);
	if (base_lengh < 2)
		return (count);
	if (n < 0)
	{
		write(fd, "-", 1);
		count++;
	}
	last_nb = n % base_lengh;
	n = n / base_lengh;
	if (n < 0)
		n *= -1;
	if (n > 0)
		count += ft_putnbr_base_fd(n, base, fd);
	if (last_nb < 0)
		last_nb *= -1;
	write(fd, &base[last_nb], 1);
	count++;
	return (count);
}

int	ft_putptr_pf_fd(unsigned long n, int fd)
{
	int		last_nb;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	last_nb = n % 16;
	n = n / 16;
	if (n > 0)
		count += ft_putptr_pf_fd(n, fd);
	write(fd, &base[last_nb], 1);
	count++;
	return (count);
}

int	ft_putstr_pf_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	else
	{
		write(fd, "(null)", 6);
		i = 6;
	}
	return (i);
}

int	ft_putchar_pf_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
