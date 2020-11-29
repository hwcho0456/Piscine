/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:53:32 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 17:57:11 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		validate_input(char *str)
{
	int	count;
	int	state;
	int	len;

	state = 0;
	count = 0;
	len = -1;
	while (*(str + (++len)))
	{
		if (*(str + len) != ' ' && (*(str + len) < '0' || *(str + len) > '9'))
			return (-1);
		else if (*(str + len) == ' ')
			state = 0;
		else
		{
			if (state == 0)
			{
				state = 1;
				count++;
			}
		}
	}
	if (count % 4 != 0)
		return (-1);
	return (count / 4);
}

int		**initialize_condition(int n)
{
	int **condition;
	int i;

	if (n == -1)
		return (0);
	condition = (int **)malloc(sizeof(int *) * 4);
	if (!condition)
		return (0);
	i = -1;
	while (++i < 4)
	{
		condition[i] = (int *)malloc(sizeof(int) * n);
		if (!condition[i])
		{
			while (--i >= 0)
				free(condition[i]);
			free(condition);
			return (0);
		}
	}
	return (condition);
}

void	assign_condition(int *i, int *j, int n)
{
	*j += 1;
	if (*j == n)
	{
		*i += 1;
		*j = 0;
	}
}

int		**save_input(int **condition, int n, char *str)
{
	int state;
	int i;
	int j;

	i = 0;
	j = -1;
	state = 0;
	while (*str)
	{
		if (*str == ' ')
			state = 0;
		else
		{
			if (state == 0)
			{
				assign_condition(&i, &j, n);
				state = 1;
				condition[i][j] = *str - '0';
			}
			else
				condition[i][j] = 10 * condition[i][j] + *str - '0';
		}
		str++;
	}
	return (condition);
}

int		**process_input(char *str, int n)
{
	int **condition;

	if (n <= 0 || n >= 13)
		return (0);
	condition = initialize_condition(n);
	if (!condition)
		return (0);
	condition = save_input(condition, n, str);
	return (condition);
}
