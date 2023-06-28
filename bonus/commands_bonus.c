/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:51:44 by njegat            #+#    #+#             */
/*   Updated: 2023/03/13 16:45:33 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	ft_execute(t_data *data, int pos, int fd_file, char **env)
{
	ft_dup2_mana(data, pos, fd_file);
	ft_close_all(data, fd_file, pos);
	if (execve(data->cmdx[pos].cmd[0], data->cmdx[pos].cmd, env) == -1)
	{
		perror("execve");
		ft_free_cmdx(data);
		exit (1);
	}
}

void	ft_exec_cmdx(t_data *data, int pos, int fd_file, char **env)
{
	data->child = fork();
	if (data->child == -1)
		perror("fork");
	if (data->child == 0)
	{
		if (data->cmdx[pos].cmd[0])
		{
			if (access(data->cmdx[pos].cmd[0], X_OK) != -1)
				ft_execute(data, pos, fd_file, env);
			else
				ft_print_error_cmd(data->cmdx[pos].cmd[0], data->error_path);
		}
		else
			ft_print_error_cmd("''", data->error_path);
		ft_free_cmdx(data);
		ft_close_all(data, fd_file, pos);
		exit (127);
	}
}

static void	ft_get_here_doc(t_data *data)
{
	char	*str;

	while (1)
	{
		str = ft_get_line(0);
		if (!str)
			break ;
		if (!ft_strncmp(str, data->limiter, ft_strlen(data->limiter)))
		{
			if (!ft_strncmp(str, data->limiter, ft_strlen(str) - 1))
				break ;
		}
		ft_putstr_fd(str, data->pipefd2[1]);
		free(str);
	}
	free(str);
}

static void	ft_close_end_pipe(t_data *data, int pos)
{
	if (pos % 2)
		close(data->pipefd2[0]);
	else
		close(data->pipefd1[0]);
}

void	ft_command_handler(t_data *data, char **env)
{
	int		i;
	pid_t	child_old;

	i = 0;
	child_old = -1;
	while (i < data->nb_command)
	{
		ft_set_pipe(data, i);
		if ((i == 0 && !data->limiter) || i == data->nb_command - 1)
			ft_cmd_files(i, data, env);
		else if (i == 0 && data->limiter)
		{
			ft_get_here_doc(data);
			ft_exec_cmdx(data, i, -1, env);
		}
		else
		{
			ft_exec_cmdx(data, i, -1, env);
			child_old = data->child;
		}
		i++;
	}
	waitpid(child_old, NULL, 0);
	ft_close_end_pipe(data, i);
}
