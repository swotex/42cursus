/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:22:05 by njegat            #+#    #+#             */
/*   Updated: 2023/03/13 17:02:51 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
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
	t_cmd	cmd1;
	t_cmd	cmd2;
	pid_t	child;
	int		pipefd[2];
	char	*infile;
	char	*outfile;
	int		error_path;
}			t_data;

int		ft_path_handler(t_data *data, char **argv, char **env);
void	ft_command_handler(t_data *data, char **env);

#endif