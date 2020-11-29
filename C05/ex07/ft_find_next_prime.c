/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:11:16 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 18:24:38 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int square;
	int a;
	int i;

	if (nb <= 1)
		return (0);
	square = 1;
	a = 1;
	while (square <= nb)
	{
		a++;
		square = a * a;
	}
	i = 1;
	while (++i <= a)
	{
		if (nb % i == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	if (i <= 1)
		return (2);
	while (1)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
}
