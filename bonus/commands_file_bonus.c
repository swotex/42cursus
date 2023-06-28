/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:42:20 by njegat            #+#    #+#             */
/*   Updated: 2023/03/13 16:43:59 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	ft_cmd_outfile(int pos, t_data *data, char **env)
{
	int	fd_file;

	if (pos == data->nb_command - 1)
	{
		if (data->limiter)
			fd_file = open(data->outfile, O_APPEND | O_CREAT | O_WRONLY, 0644);
		else
			fd_file = open(data->outfile, O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (fd_file != -1)
		{
			ft_exec_cmdx(data, pos, fd_file, env);
			close(fd_file);
		}
		else
		{
			write(2, "pipex: ", 7);
			perror(data->outfile);
		}
	}
}

void	ft_cmd_files(int pos, t_data *data, char **env)
{
	int	fd_file;

	if (pos == 0)
	{
		fd_file = open(data->infile, O_RDONLY, 0644);
		if (fd_file != -1)
		{
			ft_exec_cmdx(data, pos, fd_file, env);
			close(fd_file);
		}
		else
		{
			write(2, "pipex: ", 7);
			perror(data->infile);
		}
	}
	else
		ft_cmd_outfile(pos, data, env);
}
