/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 04:43:18 by hcho              #+#    #+#             */
/*   Updated: 2020/11/26 18:02:31 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int n;

int g_cases; // 총 경우의 수

int g_positions[20]; // 퀸의 각 행에서의 열 위치

int possible(int col, int row) // col행 row열의 가능성 
{
	int j;

	j = 0;
	while(j < col)
	{
		if (g_positions[j] == row) // 열 중복
			return (0);
        if (g_positions[j] - row == j - col) // y=x 대각선
			return (0);
		if (g_positions[j] - row == col - j) // y=-x 대각선
			return (0);
		j++;
	}
	return (1);
}

void	dfs(int col) // 직전 퀸의 위치를 정보로 받음
{
    int i;
	int j;
	char pos;

	if (col == n - 1) // 직전 퀸이 마지막 행
	{
		j = 0;
		while (j < n)
		{	
			pos = g_positions[j] + '0';
			//write(1, &pos, 1);
			j++;
		}
		//write(1,"\n",1);
		g_cases++; // 경우의 수 증가
        return ;
	}
		
	i = 0;
	while (i <  n) // 각 행에서 0 ~ n-1 열에 놓일 수 있음
	{
        g_positions[col + 1] = i;
        if (possible(col + 1, i)) 
            dfs(col + 1);
        i++;
	}
}

int	ft_ten_queens_puzzle(int size)
{
	int i;

    n = size;
	g_cases = 0; // 경우의 수 초기화
	i = 0;
	while(i < n)
    {
		g_positions[0] = i;
		dfs(0);
		i++;
	}
	return g_cases;
}

int main()
{
    for (int i = 1; i<12; i++) 
	    printf("%d개에서 가능한 가짓수 : %d\n",i, ft_ten_queens_puzzle(i));
	return 0;
}
