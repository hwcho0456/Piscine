/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:18:32 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 13:23:11 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		see_left_line(int **maps, int line, int n)
{
	int j;
	int max;
	int count;

	j = -1;
	max = 0;
	count = 0;
	while (++j < n)
	{
		if (max < maps[line][j])
		{
			count++;
			max = maps[line][j];
		}
	}
	return (count);
}

int		see_right_line(int **maps, int line, int n)
{
	int j;
	int max;
	int count;

	j = n;
	max = 0;
	count = 0;
	while (--j >= 0)
	{
		if (max < maps[line][j])
		{
			count++;
			max = maps[line][j];
		}
	}
	return (count);
}

int		check_overlap(int **maps, int line, int n)
{
	int i;
	int j;

	j = -1;
	while (++j < n)
	{
		i = -1;
		while (++i < line)
		{
			if (maps[line][j] == maps[i][j])
				return (0);
		}
	}
	return (1);
}

int		see_up_column(int **maps, int col, int n)
{
	int i;
	int max;
	int count;

	i = -1;
	max = 0;
	count = 0;
	while (++i < n)
	{
		if (max < maps[i][col])
		{
			count++;
			max = maps[i][col];
		}
	}
	return (count);
}

int		see_down_column(int **maps, int col, int n)
{
	int i;
	int max;
	int count;

	i = n;
	max = 0;
	count = 0;
	while (--i >= 0)
	{
		if (max < maps[i][col])
		{
			count++;
			max = maps[i][col];
		}
	}
	return (count);
}
