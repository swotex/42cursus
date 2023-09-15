/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 05:26:31 by njegat            #+#    #+#             */
/*   Updated: 2023/07/13 04:32:11 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include "../../libft/libft.h"

enum e_error_flags
{
	ARGS = 12,
	FEXT = 13,
	OFILE = 14,
	ALLOC = 15,
	CDUP = 16,
	FORMAT = 17,
	MISST = 18,
	FCOLOR = 19,
	MFORMAT = 20,
	MEMPTY = 21,
	MOPEN = 22,
	IFILE = 23
};

//parsing
void	exit_error_parsing(int flag, char *str);

#endif
