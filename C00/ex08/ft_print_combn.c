/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:08:49 by hcho              #+#    #+#             */
/*   Updated: 2020/11/21 11:39:21 by hcho             ###   ########.fr       */
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
		if (g_comb[0] != '0' + (10 - n))
			write(1, ", ", 2);
		return ;
	}
	curr = prev;
	while (++curr <= 10 - g_len + n)
	{
		g_comb[n] = '0' + curr;
		rec(curr, n + 1);
	}
}

void	ft_print_combn(int n)
{
	int start;
	char ch;

	start = 0;
	g_len = n;
	while (start <= 10 - n)
	{
		g_comb[0] = '0' + start;
		rec(start, 1);
		start++;
	}
}
