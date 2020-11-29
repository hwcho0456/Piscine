/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 08:43:32 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 20:42:49 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int len;

	len = 0;
	while ((*(s1 + len) == *(s2 + len)) && *(s1 + len) && *(s2 + len))
		len++;
	return (*(s1 + len) - *(s2 + len));
}

void	swap(char **argv, int a, int b)
{
	char *temp;

	temp = argv[a];
	argv[a] = argv[b];
	argv[b] = temp;
}

int		partition(char **argv, int left, int right)
{
	char	*pivot;
	int		low;
	int		high;

	pivot = argv[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && ft_strcmp(pivot, argv[low]) >= 0)
			low++;
		while (high >= left + 1 && ft_strcmp(pivot, argv[high]) <= 0)
			high--;
		if (low <= high)
			swap(argv, low, high);
	}
	swap(argv, left, high);
	return (high);
}

void	quicksort(char **argv, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(argv, left, right);
		quicksort(argv, left, pivot - 1);
		quicksort(argv, pivot + 1, right);
	}
}

int		main(int argc, char *argv[])
{
	int	n;

	if (argc < 1)
		return (0);
	quicksort(argv, 1, argc - 1);
	n = 0;
	while (n < argc)
	{
		while (*argv[n])
		{
			write(1, argv[n], 1);
			argv[n]++;
		}
		write(1, "\n", 1);
		n++;
	}
	return (0);
}
