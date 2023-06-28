/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:40:56 by njegat            #+#    #+#             */
/*   Updated: 2023/01/23 14:06:45 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newline(int fd, char *line)
{
	char	*buffer;
	int		backread;

	buffer = malloc((BUFFER_SIZE + 1 * sizeof(char)));
	if (!buffer)
		return (NULL);
	backread = 1;
	while (!ft_strfind(line, '\n') && backread != 0)
	{
		backread = read(fd, buffer, BUFFER_SIZE);
		if (backread == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[backread] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_cutline(char *line)
{
	char	*output;
	int		i;

	output = malloc((ft_linelen(line) + 2) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (i <= ft_linelen(line))
	{
		output[i] = line[i];
		i++;
	}
	if (output[i - 1] == '\n')
		output[i] = '\0';
	return (output);
}

char	*ft_cutsave(char *line)
{
	int		i;
	int		j;
	char	*save;

	i = ft_linelen(line) + 1;
	j = 0;
	if (line[i - 1] == '\0')
	{
		free(line);
		return (NULL);
	}
	while (line[i + j])
		j++;
	save = malloc((j + 1) * sizeof(char));
	if (!save)
		return (NULL);
	j = 0;
	while (line[i + j])
	{
		save[j] = line[i + j];
		j++;
	}
	save[j] = '\0';
	free(line);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
	{
		save = malloc(sizeof(char));
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	save = ft_newline(fd, save);
	if (!save)
		return (NULL);
	output = ft_cutline(save);
	if (!output)
		return (NULL);
	save = ft_cutsave(save);
	if (!*output)
	{
		free(output);
		return (NULL);
	}
	return (output);
}
