/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:37:41 by hcho              #+#    #+#             */
/*   Updated: 2020/11/25 23:45:45 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	if (c >= '\t' && c <= '\r')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	unsigned int	minus;
	unsigned int	len;
	int				sign;
	int				number;

	while (is_space(*str))
		str++;
	minus = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus++;
		str++;
	}
	sign = (minus % 2 == 1) ? -1 : 1;
	len = 0;
	number = 0;
	while (*(str + len))
	{
		if (*(str + len) < '0' || *(str + len) > '9')
			break ;
		number = 10 * number + (*(str + len) - '0');
		len++;
	}
	return (sign * number);
}
