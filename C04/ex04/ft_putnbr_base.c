/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 07:45:24 by hcho              #+#    #+#             */
/*   Updated: 2020/11/30 21:22:56 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	cur(int nbr, int len, char *base)
{
	if (nbr == 0)
		return ;
	cur(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
}

int		check_base(char *base)
{
	int	len;
	int	i;

	len = -1;
	while (*(base + (++len)))
	{
		if (*(base + len) == '-' || *(base + len) == '+')
			return (0);
		i = 0;
		while (*(base + len + (++i)))
		{
			if (*(base + len + i) == *(base + len))
				return (0);
		}
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = check_base(base);
	if (len <= 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		cur(-(nbr / len), len, base);
		write(1, &base[-(nbr % len)], 1);
	}
	else
	{
		cur(nbr / len, len, base);
		write(1, &base[nbr % len], 1);
	}
}
