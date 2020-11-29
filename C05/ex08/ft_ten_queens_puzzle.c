/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 04:43:18 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 18:44:42 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_n;
int		g_cases;
int		g_positions[20];

int		possible(int col, int row)
{
	int	j;

	j = 0;
	while (j < col)
	{
		if (g_positions[j] == row)
			return (0);
		if (g_positions[j] - row == j - col)
			return (0);
		if (g_positions[j] - row == col - j)
			return (0);
		j++;
	}
	return (1);
}

void	dfs(int col)
{
	int		i;
	int		j;
	char	pos;

	if (col == g_n - 1)
	{
		j = 0;
		while (j < g_n)
		{
			pos = g_positions[j] + '0';
			write(1, &pos, 1);
			j++;
		}
		write(1, "\n", 1);
		g_cases++;
		return ;
	}
	i = 0;
	while (i < g_n)
	{
		g_positions[col + 1] = i;
		if (possible(col + 1, i))
			dfs(col + 1);
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int i;

	g_n = 10;
	g_cases = 0;
	i = 0;
	while (i < g_n)
	{
		g_positions[0] = i;
		dfs(0);
		i++;
	}
	return (g_cases);
}
