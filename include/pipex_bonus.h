/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:41:48 by njegat            #+#    #+#             */
/*   Updated: 2023/03/13 16:44:39 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_cmd
{
	char	**cmd;
}			t_cmd;

typedef struct s_data
{
	t_cmd	*cmdx;
	int		nb_command;
	int		pipefd1[2];
	int		pipefd2[2];
	char	*infile;
	char	*outfile;
	char	*limiter;
	pid_t	child;
	int		error_path;
}			t_data;

int		ft_get_command_path(t_data *data, char **env);
void	ft_command_handler(t_data *data, char **env);
void	ft_free_cmdx(t_data *data);
void	ft_set_pipe(t_data *data, int pos);
void	ft_close_all(t_data *data, int fd_file, int pos);
void	ft_dup2_mana(t_data *data, int pos, int fd_file);
void	ft_exec_cmdx(t_data *data, int pos, int fd_file, char **env);
void	ft_cmd_files(int pos, t_data *data, char **env);
void	ft_print_error_cmd(char *cmd, int error_path);

#endif