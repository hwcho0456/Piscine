/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:11:16 by hcho              #+#    #+#             */
/*   Updated: 2020/11/30 09:51:20 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	approx_sqrt(int nb)
{
	double	a;
	int		i;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	a = nb / 2;
	i = 0;
	while (i < 30)
	{
		a = 0.5 * (a + nb / a);
		i++;
	}
	return (int)a;
}

int	ft_is_prime(int nb)
{
	int i;
	int a;

	if (nb <= 1)
		return (0);
	if (nb % 2 == 0)
		return (0);
	a = approx_sqrt(nb);
	i = 3;
	while (i <= a)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 2)
		return (2);
	i = (nb % 2 == 0) ? nb + 1 : nb;
	while (1)
	{
		if (ft_is_prime(i))
			return (i);
		i += 2;
	}
}
