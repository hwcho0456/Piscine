/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 04:43:18 by hcho              #+#    #+#             */
/*   Updated: 2020/11/26 07:53:24 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	g_cases;

int	positions[5][2];

int possible(int row, int column)
{
	int j;

	j = 0;
	while(j < column)
	{
		if (positions[j][0] == row)
			return (0);
		if (positions[j][0] - row == positions[j][1] - column)
			return (0);
		if (positions[j][0] - row == column - positions[j][1])
			return (0);
		j++;
	}
	return (1);
}

void	dfs(int row, int column)
{
	//int p;
	//char c;

	if (column == 5)
	{
		for(int x=0; x<5; x++)
			printf("%d ", positions[x][0]);
		printf("\n");

	/*	c = 0;
		p = 0;
		while (p < 5)
		{	
			c = '0' + positions[p][0];
			write(1, &c, 1);
			p++;
		}
		write(1,"\n",1);
		g_cases += 1;*/
		return ;
	}
		
	int i = 0;
	while (i <  5)
	{
		if (!possible(i,column + 1))
		{
			positions[column + 1][0] = i;
			positions[column + 1][1] = column + 1;
			dfs(i,column + 1);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int i;

	g_cases = 0;
	i = 0;
	while(i < 5)
	{
		positions[0][0] = i;
		positions[0][1] = 0;
		dfs(i,0);
		i++;
	}
	return g_cases;
}

int main()
{
	printf("%d\n", ft_ten_queens_puzzle());
	return 0;
}
