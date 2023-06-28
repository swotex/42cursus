/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:52:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/05 14:10:10 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_start_alloc(char **s)
{
	if (*s)
		free(*s);
	*s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*s))
	{
		*s = NULL;
		return ;
	}
}

void	gnl_free_all(char **s1, char **s2)
{
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

void	gnl_free_one(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

int	ft_stock_read(char **p_stock, int fd)
{
	int	ret;

	ft_start_alloc(p_stock);
	ret = read(fd, *p_stock, BUFFER_SIZE);
	if (ret < 0)
	{
		free(*p_stock);
		*p_stock = NULL;
		return (ret);
	}
	(*p_stock)[ret] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*str;
	int			ret;

	ret = BUFFER_SIZE;
	str = NULL;
	if (BUFFER_SIZE < 1)
		return (NULL);
	if (stock)
	{
		str = gnl_strjoin(str, stock);
		stock = gnl_realloc_stock(stock);
	}
	if (!stock)
	{
		while (!gnl_find_nl(stock) && ret == BUFFER_SIZE)
		{
			ret = ft_stock_read(&stock, fd);
			if (!stock || ret < 0 || (stock[0] == '\0' && !str))
				gnl_free_all(&str, &stock);
			str = gnl_strjoin(str, stock);
		}
		stock = gnl_realloc_stock(stock);
	}
	return (str);
}
