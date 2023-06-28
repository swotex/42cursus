/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:31:24 by njegat            #+#    #+#             */
/*   Updated: 2023/03/13 17:03:37 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**ft_get_path(char **env)
{
	int		i;
	char	**output;
	char	*tmp;

	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	output = ft_split(env[i], ':');
	if (!output)
		return (NULL);
	tmp = ft_strtrim(output[0], "PATH=");
	if (tmp)
	{
		free(output[0]);
		output[0] = tmp;
	}
	return (output);
}

static void	ft_path_finding(t_cmd *cmd, char **multi_path)
{
	int		i;
	char	*output;

	i = 0;
	while (multi_path[i])
	{
		output = ft_strdup(multi_path[i]);
		output = ft_strjoin(output, "/");
		output = ft_strjoin(output, cmd->cmd[0]);
		if (access(output, X_OK) == 0)
		{
			free(cmd->cmd[0]);
			cmd->cmd[0] = output;
			break ;
		}
		free(output);
		i++;
	}
}

int	ft_path_handler(t_data *data, char **argv, char **env)
{
	char	**multi_path;

	data->cmd1.cmd = ft_split(argv[2], ' ');
	data->cmd2.cmd = ft_split(argv[3], ' ');
	multi_path = ft_get_path(env);
	if (!multi_path)
		return (1);
	if (data->cmd1.cmd[0] && access(data->cmd1.cmd[0], X_OK) == -1)
		ft_path_finding(&data->cmd1, multi_path);
	if (data->cmd2.cmd[0] && access(data->cmd2.cmd[0], X_OK) == -1)
		ft_path_finding(&data->cmd2, multi_path);
	ft_double_free(multi_path);
	return (0);
}
