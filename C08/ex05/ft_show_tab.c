/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:19:01 by hcho              #+#    #+#             */
/*   Updated: 2020/12/02 13:43:08 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
	{
		write(1, str + len, 1);
		len++;
	}
}

void	cur(int nbr)
{
	char digit;

	if (nbr == 0)
		return ;
	cur(nbr / 10);
	digit = nbr % 10 + '0';
	write(1, &digit, 1);
}

void	ft_putnbr(int nbr)
{
	char digit;

	if (nbr < 0)
	{
		write(1, "-", 1);
		cur(-(nbr / 10));
		digit = '0' - nbr % 10;
		write(1, &digit, 1);
	}
	else
	{
		cur(nbr / 10);
		digit = nbr % 10 + '0';
		write(1, &digit, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = -1;
	while (par[++i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
	}
}
