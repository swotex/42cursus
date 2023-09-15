/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 05:51:50 by njegat            #+#    #+#             */
/*   Updated: 2023/07/30 01:41:26 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	print_error_msg(int flag, char *str)
{
	ft_printf_fd(2, "Error\n");
	if (flag == ARGS)
		ft_printf_fd(2, "Wrong number of arguments\n");
	else if (flag == FEXT)
		ft_printf_fd(2, "Wrong file extension\n");
	else if (flag == OFILE)
		ft_printf_fd(2, "open file error : %s\n", str);
	else if (flag == ALLOC)
		ft_printf_fd(2, "Memory allowance failed\n");
	else if (flag == FORMAT)
		ft_printf_fd(2, "incorrect file formatting\n");
	else if (flag == MISST)
		ft_printf_fd(2, "Missing texture(s)\n");
	else if (flag == CDUP)
		ft_printf_fd(2, "Duplicates cardinal\n");
	else if (flag == FCOLOR)
		ft_printf_fd(2, "Wrong format color: %s\n", str);
	else if (flag == MFORMAT)
		ft_printf_fd(2, "Unexpected character in the map\n");
	else if (flag == MEMPTY)
		ft_printf_fd(2, "Empty line in the map\n");
	else if (flag == IFILE)
		ft_printf_fd(2, "Incomplete file\n");
	else if (flag == MOPEN)
		ft_printf_fd(2, "Badly formatted map : %s\n", str);
}

void	exit_error_parsing(int flag, char *str)
{
	print_error_msg(flag, str);
	exit(flag);
}
