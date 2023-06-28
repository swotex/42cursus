/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:19:12 by njegat            #+#    #+#             */
/*   Updated: 2022/10/28 17:01:48 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoi_check(long long int final, int nb, int negative)
{
	if ((final > 922337203685477580) || (final == 922337203685477580 && nb > 7))
	{
		if (negative == -1)
			return (0);
		else
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int				negative;
	long long int	final;

	negative = 1;
	final = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		negative = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (ft_atoi_check(final, (*nptr - 48), negative) != 1)
		{
			final = ft_atoi_check(final, (*nptr - 48), negative);
			return (final);
		}
		final = final * 10 + (*nptr - 48);
		nptr++;
	}
	return (negative * final);
}
