/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:35:36 by njegat            #+#    #+#             */
/*   Updated: 2023/01/08 15:27:48 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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
