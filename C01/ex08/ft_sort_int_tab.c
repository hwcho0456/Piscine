/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 08:15:26 by hcho              #+#    #+#             */
/*   Updated: 2020/11/22 02:22:57 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int a, int b)
{
	int temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

int		partition(int *tab, int left, int right)
{
	int pivot;
	int low;
	int high;

	pivot = tab[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && pivot >= tab[low])
			low++;
		while (high >= left + 1 && pivot <= tab[high])
			high--;
		if (low <= high)
			swap(tab, low, high);
	}
	swap(tab, left, high);
	return (high);
}

void	quicksort(int *tab, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(tab, left, right);
		quicksort(tab, left, pivot - 1);
		quicksort(tab, pivot + 1, right);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	quicksort(tab, 0, size - 1);
}
