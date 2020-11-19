/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:50:35 by hcho              #+#    #+#             */
/*   Updated: 2020/11/19 22:18:54 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec(int nb)
{
	char digit;

	if (nb == 0)
		return ;
	rec(nb / 10);
	digit = '0' + nb % 10;
	write(1, &digit, 1);
}

void	ft_putnbr(int nb)
{
	char digit;

	if (nb < 0)
	{
		write(1, "-", 1);
		rec(-(nb / 10));
		digit = '0' - nb % 10;
	}
	else
	{
		rec(nb / 10);
		digit = '0' + nb % 10;
	}
	write(1, &digit, 1);
}
