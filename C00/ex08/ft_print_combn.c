/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:55:56 by hcho              #+#    #+#             */
/*   Updated: 2020/11/21 21:50:18 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_len;
char g_comb[10];

void	rec(int prev, int n)
{
	int curr;

	if (n == g_len)
	{
		write(1, g_comb, g_len);
		if (g_comb[0] != (10 - n) + '0')
			write(1, ", ", 2);
		return ;
	}
	curr = prev;
	while (++curr <= 10 - g_len + n)
	{
		g_comb[n] = curr + '0';
		rec(curr, n + 1);
	}
}

void	ft_print_combn(int n)
{
	int start;

	start = 0;
	g_len = n;
	while (start <= 10 - n)
	{
		g_comb[0] = start + '0';
		rec(start++, 1);
	}
}
