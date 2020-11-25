/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:36:50 by hcho              #+#    #+#             */
/*   Updated: 2020/11/26 00:32:47 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int				str_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi(char *str, unsigned int b_len, char *base)
{
	unsigned int	minus;
	unsigned int	len;
	int				sign;
	int				number;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	minus = 0;
	while (*str == '+' || *str == '-')
	{
		minus = (*str == '-') ? minus + 1 : minus;
		str++;
	}
	sign = (minus % 2 == 1) ? -1 : 1;
	len = 0;
	number = 0;
	while (*(str + len))
	{
		if (str_in_base(*(str + len), base) == -1)
			break ;
		number = b_len * number + str_in_base(*(str + len), base);
		len++;
	}
	return (sign * number);
}

unsigned int	check_base(char *base)
{
	unsigned int	len;
	int				i;

	len = -1;
	while (*(base + (++len)))
	{
		i = 0;
		while (*(base + len + (++i)))
		{
			if (*(base + len + i) == *(base + len))
				return (0);
			if (*(base + len + i) == '-' || *(base + len + i) == '+')
				return (0);
		}
	}
	return (len);
}

int				ft_atoi_base(char *str, char *base)
{
	int				nbr;
	unsigned int	len;

	len = check_base(base);
	if (len <= 1)
		return (0);
	nbr = ft_atoi(str, len, base);
	return (nbr);
}
