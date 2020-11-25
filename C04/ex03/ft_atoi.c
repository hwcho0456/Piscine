/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:37:41 by hcho              #+#    #+#             */
/*   Updated: 2020/11/25 21:32:31 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	unsigned int	len;
	int				msb;
	int				number;

	number = 0;
	msb = 1;
	if (*str == '-')
	{
		msb = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	len = 0;
	while (*(str + len))
	{
		if (*(str + len) < '0' || *(str + len) > '9')
			break ;
		number = 10 * number + (*(str + len) - '0');
		len++;
	}
	return (msb * number);
}
