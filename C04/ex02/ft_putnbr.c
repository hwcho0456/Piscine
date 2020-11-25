/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 05:50:05 by hcho              #+#    #+#             */
/*   Updated: 2020/11/26 04:15:17 by hcho             ###   ########.fr       */
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
		write(1, &digit, 1);
	}
	else
	{
		rec(nb / 10);
		digit = '0' + nb % 10;
		write(1, &digit, 1);
	}
}
