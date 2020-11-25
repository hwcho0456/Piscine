/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 07:45:24 by hcho              #+#    #+#             */
/*   Updated: 2020/11/26 04:17:15 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			cur(int nbr, unsigned int len, char *base)
{
	if (nbr == 0)
		return ;
	cur(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
}

unsigned int	check_base(char *base)
{
	unsigned int	len;
	int				i;

	len = -1;
	while (*(base + (++len)))
	{
		i = 0;
		while (*(base + len + (++i)))
		{
			if (*(base + len + i) == *(base + len))
				return (0);
			if (*(base + len + i) == '-' || *(base + len + i) == '+')
				return (0);
		}
	}
	return (len);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;

	len = check_base(base);
	if (len <= 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		cur(-(nbr / (int)len), len, base);
		write(1, &base[-nbr % len], 1);
	}
	else
	{
		cur(nbr / len, len, base);
		write(1, &base[nbr % len], 1);
	}
}
