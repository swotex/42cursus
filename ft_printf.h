/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:15:01 by njegat            #+#    #+#             */
/*   Updated: 2022/11/11 18:09:36 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_manage_nbr(va_list param_info, char c);
int	ft_manage_characters(va_list param_info, char c);
int	ft_manage_hexa(va_list param_info, char c);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nbr, int w_number);
int	ft_putnbr_unsigned(unsigned int nbr, int w_number);
int	ft_putnbr_base(unsigned long nbr, char *base, int w_number);

#endif