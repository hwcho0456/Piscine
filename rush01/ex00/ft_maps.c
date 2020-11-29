/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:35:06 by jeson             #+#    #+#             */
/*   Updated: 2020/11/29 16:26:49 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "util.h"
#include "check_condition.h"

int g_find;
int g_factorial_n;

void	freemaps(int **maps, int n)
{
	int i;

	i = -1;
	while (++i < n)
		free(maps[i]);
	free(maps);
}

int		**initialize_map(int n)
{
	int **maps;
	int success;
	int i;

	maps = (int **)malloc(sizeof(int *) * n);
	if (!maps)
		return (0);
	i = -1;
	success = 1;
	while (++i < n)
	{
		maps[i] = (int *)malloc(sizeof(int) * n);
		if (!maps[i])
		{
			success = 0;
			break ;
		}
	}
	if (success == 0)
	{
		while (--i >= 0)
			free(maps[i]);
		free(maps);
	}
	return (maps);
}

void	print_map(int **maps, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (n < 10)
				ft_putchar(maps[i][j] + '0');
			else
			{
				if (maps[i][j] / 10 == 0)
					ft_putchar(' ');
				else
					ft_putchar(maps[i][j] / 10 + '0');
				ft_putchar(maps[i][j] % 10 + '0');
			}
			if (j != n - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	dfs(int **maps, int line, int n, int **condition)
{
	int i;

	if (line == n)
	{
		if (check_final_condition(maps, n, condition) && g_find == 0)
		{
			print_map(maps, n);
			g_find = 1;
		}
		return ;
	}
	i = -1;
	while (++i < g_factorial_n && g_find == 0)
	{
		reset_line(maps[line], n);
		permutation(maps[line], i, n);
		if (check_line_condition(maps, line, n, condition))
			dfs(maps, line + 1, n, condition);
	}
}

void	rush(int **condition, int n)
{
	int **maps;
	int i;

	g_find = 0;
	g_factorial_n = factorial(n);
	maps = initialize_map(n);
	if (check_initial_condition(condition, n) == 0 || !(maps))
	{
		write(1, "Error\n", 6);
		return ;
	}
	i = -1;
	while (++i < g_factorial_n && g_find == 0)
	{
		reset_line(maps[0], n);
		permutation(maps[0], i, n);
		if (check_line_condition(maps, 0, n, condition))
			dfs(maps, 1, n, condition);
	}
	if (g_find == 0)
	{
		write(1, "Error\n", 6);
		return ;
	}
	freemaps(maps, n);
}
