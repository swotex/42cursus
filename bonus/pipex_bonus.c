/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:31:55 by njegat            #+#    #+#             */
/*   Updated: 2023/03/13 15:41:06 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_init(int argc, char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 2;
	data->infile = argv[1];
	data->limiter = NULL;
	data->nb_command = argc - 3;
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		data->limiter = argv[2];
		data->infile = NULL;
		data->nb_command = argc - 4;
		i++;
	}
	data->cmdx = malloc(data->nb_command * sizeof(t_cmd));
	if (!data->cmdx)
		return ;
	j = 0;
	while (i < argc - 1)
	{
		data->cmdx[j].cmd = ft_split(argv[i], ' ');
		j++;
		i++;
	}
	data->outfile = argv[i];
}

void	ft_free_cmdx(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_command)
	{
		ft_double_free(data->cmdx[i].cmd);
		i++;
	}
	free(data->cmdx);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		exit_code;

	if (argc < 5)
	{
		write(2, "wrong number of parameters\n", 27);
		return (1);
	}
	ft_init(argc, argv, &data);
	if (!data.cmdx)
		return (1);
	data.error_path = 0;
	data.child = -1;
	if (ft_get_command_path(&data, env))
		data.error_path = 1;
	ft_command_handler(&data, env);
	ft_free_cmdx(&data);
	exit_code = 0;
	waitpid(data.child, &exit_code, 0);
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
	return (WEXITSTATUS(exit_code));
}
