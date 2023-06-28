/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:46:25 by njegat            #+#    #+#             */
/*   Updated: 2023/03/14 12:05:55 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_exec_cmd1(t_data *data, int fd_file, char **env)
{
	data->child = fork();
	if (data->child == -1)
		perror("fork");
	if (data->child == 0)
	{
		if (dup2(fd_file, 0) == -1)
			perror("dup2");
		if (dup2(data->pipefd[1], 1) == -1)
			perror("dup2");
		close(fd_file);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		if (execve(data->cmd1.cmd[0], data->cmd1.cmd, env) == -1)
		{
			perror("execve");
			ft_double_free(data->cmd1.cmd);
			ft_double_free(data->cmd2.cmd);
			exit (1);
		}
	}
}

static void	ft_exec_cmd2(t_data *data, int fd_file, char **env)
{
	data->child = fork();
	if (data->child == -1)
		perror("fork");
	if (data->child == 0)
	{
		if (dup2(fd_file, 1) == -1)
			perror("dup2");
		if (dup2(data->pipefd[0], 0) == -1)
			perror("dup2");
		close(fd_file);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		if (execve(data->cmd2.cmd[0], data->cmd2.cmd, env) == -1)
		{
			perror("execve");
			ft_double_free(data->cmd1.cmd);
			ft_double_free(data->cmd2.cmd);
			exit (1);
		}
	}
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

static void	ft_second_cmd(t_data *data, char **env)
{
	int	fd_file;

	fd_file = open(data->outfile, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd_file != -1)
	{
		if (data->cmd2.cmd[0])
		{
			if (access(data->cmd2.cmd[0], X_OK) != -1)
				ft_exec_cmd2(data, fd_file, env);
			else
				ft_print_error_cmd(data->cmd2.cmd[0], data->error_path);
		}
		else
			ft_print_error_cmd("''", data->error_path);
		close(fd_file);
	}
	else
	{
		write(2, "pipex: ", 7);
		perror(data->outfile);
	}
}

void	ft_command_handler(t_data *data, char **env)
{
	int	fd_file;

	fd_file = open(data->infile, O_RDONLY, 0644);
	if (fd_file != -1)
	{
		if (data->cmd1.cmd[0])
		{
			if (access(data->cmd1.cmd[0], X_OK) != -1)
				ft_exec_cmd1(data, fd_file, env);
			else
				ft_print_error_cmd(data->cmd1.cmd[0], data->error_path);
		}
		else
			ft_print_error_cmd("''", data->error_path);
		close(fd_file);
	}
	else
	{
		write(2, "pipex: ", 7);
		perror(data->infile);
	}
	ft_second_cmd(data, env);
}
