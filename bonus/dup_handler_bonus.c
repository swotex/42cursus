/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:47:26 by njegat            #+#    #+#             */
/*   Updated: 2023/02/23 05:49:04 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	ft_dup2_infile(t_data *data, int fd_file)
{
	if (data->limiter)
	{
		if (dup2(data->pipefd2[0], 0) == -1)
			perror("dup2");
	}
	else
	{
		if (dup2(fd_file, 0) == -1)
			perror("dup2");
	}
	if (dup2(data->pipefd1[1], 1) == -1)
		perror("dup2");
}

static void	ft_dup2_outfile(t_data *data, int pos, int fd_file)
{
	if (pos % 2)
	{
		if (dup2(data->pipefd1[0], 0) == -1)
			perror("dup2");
	}
	else
	{
		if (dup2(data->pipefd2[0], 0) == -1)
			perror("dup2");
	}
	if (dup2(fd_file, 1) == -1)
		perror("dup2");
}

void	ft_dup2_mana(t_data *data, int pos, int fd_file)
{
	if (pos == 0 && (fd_file != -1 || data->limiter))
		ft_dup2_infile(data, fd_file);
	else if (pos == data->nb_command - 1 && fd_file != -1)
		ft_dup2_outfile(data, pos, fd_file);
	else if (pos % 2)
	{
		if (dup2(data->pipefd1[0], 0) == -1)
			perror("dup2");
		if (dup2(data->pipefd2[1], 1) == -1)
			perror("dup2");
	}
	else if (!(pos % 2))
	{
		if (dup2(data->pipefd2[0], 0) == -1)
			perror("dup2");
		if (dup2(data->pipefd1[1], 1) == -1)
			perror("dup2");
	}
}
