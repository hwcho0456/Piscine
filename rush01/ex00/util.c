/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:58:06 by gpaeng            #+#    #+#             */
/*   Updated: 2020/11/29 14:34:16 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		factorial(int n)
{
	int p;
	int answer;

	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	p = n + 1;
	answer = 1;
	while (--p > 0)
		answer = answer * p;
	return (answer);
}

void	swap(int *arr, int i, int j)
{
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void	permutation(int *line_map, int i, int n)
{
	int j;
	int k;

	j = n;
	while (--j > 0)
	{
		k = i / factorial(j);
		swap(line_map, n - j - 1, n - j + k - 1);
		i = i % factorial(j);
	}
}

void	reset_line(int *line, int n)
{
	int i;

	i = -1;
	while (++i < n)
		line[i] = i + 1;
}
