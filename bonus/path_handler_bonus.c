/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:12:49 by njegat            #+#    #+#             */
/*   Updated: 2023/03/13 14:27:50 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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

static void	ft_set_path(t_cmd *cmd, char **multi_path)
{
	int		j;
	char	*output;

	j = 0;
	while (multi_path[j])
	{
		output = ft_strdup(multi_path[j]);
		output = ft_strjoin(output, "/");
		output = ft_strjoin(output, cmd->cmd[0]);
		if (access(output, X_OK) == 0)
		{
			free(cmd->cmd[0]);
			cmd->cmd[0] = output;
			break ;
		}
		free(output);
		j++;
	}
}

static void	ft_path_finding(t_data *data, char **multi_path)
{
	int		i;

	i = 0;
	while (i < data->nb_command)
	{
		if (data->cmdx[i].cmd[0] && access(data->cmdx[i].cmd[0], X_OK) == -1)
		{
			ft_set_path(&data->cmdx[i], multi_path);
		}
		i++;
	}
}

int	ft_get_command_path(t_data *data, char **env)
{
	char	**multi_path;

	multi_path = ft_get_path(env);
	if (!multi_path)
		return (1);
	ft_path_finding(data, multi_path);
	ft_double_free(multi_path);
	return (0);
}
