/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:35:36 by njegat            #+#    #+#             */
/*   Updated: 2022/11/17 08:15:44 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
char	*ft_newline(int fd, char *line);
size_t	ft_strlen(const char *s);
int		ft_strfind(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_linelen(char *s);
char	*ft_cutline(char *line);
char	*ft_cutsave(char *line);

#endif
