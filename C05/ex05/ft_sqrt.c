/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:43:38 by hcho              #+#    #+#             */
/*   Updated: 2020/11/30 09:46:58 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
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
	if (a - (double)(int)a <= 0.00000000001)
		return (int)a;
	return (0);
}
