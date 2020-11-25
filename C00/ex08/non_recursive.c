/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_recursive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:27:36 by hcho              #+#    #+#             */
/*   Updated: 2020/11/25 20:35:06 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_comb[10];

int		rightnumber(int n)
{
	while (n > 1)
	{
		if (g_comb[n - 1] <= g_comb[n - 2])
			return (0);
		n--;
	}
	return (1);
}

int		ten_to_n(int n)
{
	int c;
	int max;

	max = 1;
	c = 0;
	while (c < n)
	{
		max = max * 10;
		c++;
	}
	return (max);
}

void	ft_print_combn(int n)
{
	int number;
	int digit;
	int max;
	int i;

	max = ten_to_n(n);
	number = -1;
	while (++number < max)
	{
		i = 0;
		digit = number;
		while (i < n)
		{
			g_comb[n - i - 1] = digit % 10 + '0';
			digit = digit / 10;
			i++;
		}
		if (rightnumber(n))
		{
			write(1, g_comb, n);
			if (g_comb[0] != 10 - n + '0')
				write(1, ", ", 2);
		}
	}
}
