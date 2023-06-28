/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:21:31 by njegat            #+#    #+#             */
/*   Updated: 2023/03/14 11:31:30 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_init_data(t_data *data, char **argv)
{
	if (pipe(data->pipefd) == -1)
	{
		ft_double_free(data->cmd1.cmd);
		ft_double_free(data->cmd2.cmd);
		perror("pipe");
		exit(1);
	}
	data->infile = argv[1];
	data->outfile = argv[4];
	data->child = -1;
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		exit_code;

	if (argc != 5)
	{
		write(2, "wrong number of parameters\n", 27);
		return (1);
	}
	data.error_path = 0;
	if (ft_path_handler(&data, argv, env))
		data.error_path = 1;
	ft_init_data(&data, argv);
	ft_command_handler(&data, env);
	ft_double_free(data.cmd1.cmd);
	ft_double_free(data.cmd2.cmd);
	close(data.pipefd[1]);
	exit_code = 0;
	waitpid(data.child, &exit_code, 0);
	close(data.pipefd[0]);
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
	return (WEXITSTATUS(exit_code));
}
