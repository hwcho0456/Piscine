/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 07:45:24 by hcho              #+#    #+#             */
/*   Updated: 2020/11/24 08:46:33 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	cur(int nbr)
{
	if (nbr == 0)
		return;
	cur(nbr / len);
	write(1, &base[nbr % len], 1);
}	

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	unsigned int	i;

	n_base = 0 
	len = -1;
   	while(*(base + (++len)))
	{
		i = -1;
		while(*(base + len + (++i)))
			if (*(base + len + i) == *(base + len) || *(base + len + i) == ('-' || '+'))
				return ;
	}
	if (len <= 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		cur(-nbr / len);
		write(1, &base[-nbr % len], 1);
	}
	else
	{
		cur(nbr / len);
		write(1, &base[nbr % len], 1);
	}
}
