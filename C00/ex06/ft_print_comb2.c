/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:49:40 by hcho              #+#    #+#             */
/*   Updated: 2020/11/21 21:57:39 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	increment(char *a, char *b)
{
	if (*b == '9')
	{
		if (*a == '9')
			*a = '0';
		else
			*a += 1;
		*b = '0';
	}
	else
		*b += 1;
}

void	ft_print_comb2(void)
{
	char word[7];

	word[0] = '0';
	word[1] = '0';
	word[2] = ' ';
	word[5] = ',';
	word[6] = ' ';
	while (word[0] != '9' || word[1] != '8')
	{
		word[3] = word[0];
		word[4] = word[1];
		increment(&word[3], &word[4]);
		while (word[3] != '0' || word[4] != '0')
		{
			write(1, word, 7);
			increment(&word[3], &word[4]);
		}
		increment(&word[0], &word[1]);
	}
	write(1, "98 99", 5);
}
