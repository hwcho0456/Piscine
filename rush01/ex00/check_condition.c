/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condtion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:35:38 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 14:32:14 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "condition_util.h"

int		check_initial_condition(int **condition, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (condition[0][i] <= 0 || condition[1][i] <= 0)
			return (0);
		if (condition[2][i] <= 0 || condition[3][i] <= 0)
			return (0);
		if (condition[0][i] + condition[1][i] > n + 1)
			return (0);
		if (condition[2][i] + condition[3][i] > n + 1)
			return (0);
	}
	return (1);
}

int		check_line_condition(int **maps, int line, int n, int **condition)
{
	if (see_left_line(maps, line, n) != condition[2][line])
		return (0);
	if (see_right_line(maps, line, n) != condition[3][line])
		return (0);
	if (check_overlap(maps, line, n) == 0)
		return (0);
	return (1);
}

int		check_final_condition(int **maps, int n, int **condition)
{
	int j;

	j = -1;
	while (++j < n)
	{
		if (see_up_column(maps, j, n) != condition[0][j])
			return (0);
		if (see_down_column(maps, j, n) != condition[1][j])
			return (0);
	}
	return (1);
}
