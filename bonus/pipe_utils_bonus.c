/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:43:01 by njegat            #+#    #+#             */
/*   Updated: 2023/03/14 11:55:57 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_close_all(t_data *data, int fd_file, int pos)
{
	if (pos == 0 && !data->limiter)
	{
		close(data->pipefd1[0]);
		close(data->pipefd1[1]);
	}
	else if (pos == data->nb_command - 1)
	{
		if (pos % 2)
			close(data->pipefd1[0]);
		else
			close(data->pipefd2[0]);
	}
	else
	{
		close(data->pipefd1[0]);
		close(data->pipefd1[1]);
		close(data->pipefd2[0]);
		close(data->pipefd2[1]);
	}
	if (fd_file != -1)
		close(fd_file);
}

void	ft_print_error_cmd(char *cmd, int error_path)
{
	if (ft_strfind(cmd, '/') || error_path == 1)
	{
		write(2, "pipex: ", 7);
		write(2, cmd, ft_strlen(cmd));
		ft_putendl_fd(": No such file or directory", 2);
	}
	else
	{
		write(2, "pipex: ", 7);
		write(2, cmd, ft_strlen(cmd));
		ft_putendl_fd(": command not found", 2);
	}
}

static void	ft_init_pipe(t_data *data, int nb_pipe)
{
	if (nb_pipe == 1)
	{
		if (pipe(data->pipefd1) == -1)
		{
			ft_free_cmdx(data);
			close(data->pipefd2[0]);
			close(data->pipefd2[1]);
			perror("pipe");
			exit(1);
		}
	}
	else if (nb_pipe == 2)
	{
		if (pipe(data->pipefd2) == -1)
		{
			ft_free_cmdx(data);
			close(data->pipefd1[0]);
			close(data->pipefd1[1]);
			perror("pipe");
			exit(1);
		}
	}
}

static void	ft_set_pipe_cmdx(t_data *data, int pos)
{
	if (pos % 2)
	{
		if (pos > 1 || data->limiter)
		{
			close(data->pipefd2[0]);
			close(data->pipefd2[1]);
		}
		ft_init_pipe(data, 2);
	}
	else if (!(pos % 2))
	{
		close(data->pipefd1[0]);
		close(data->pipefd1[1]);
		ft_init_pipe(data, 1);
	}
}

void	ft_set_pipe(t_data *data, int pos)
{
	if (pos == 0)
	{
		ft_init_pipe(data, 1);
		if (data->limiter)
			ft_init_pipe(data, 2);
	}
	else if (pos == data->nb_command - 1 && (pos > 1 || data->limiter))
	{
		close(data->pipefd2[1]);
		close(data->pipefd1[1]);
		if (pos % 2)
			close(data->pipefd2[0]);
		else
			close(data->pipefd1[0]);
	}
	else if (pos == data->nb_command - 1 && pos == 1)
		close(data->pipefd1[1]);
	else
		ft_set_pipe_cmdx(data, pos);
}
