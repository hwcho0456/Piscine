/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:22:21 by hcho              #+#    #+#             */
/*   Updated: 2020/11/30 14:43:01 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa(int nbr, int b_len, char *base);

int		str_in_base(char c, char *base)
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

int		ft_atoi(char *str, int b_len, char *base)
{
	int	minus;
	int	len;
	int	sign;
	int	number;

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

int		check_base(char *base)
{
	int	len;
	int	i;

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
			if (*(base + len + i) >= '\t' && *(base + len + i) <= '\r')
				return (0);
			if (*(base + len + i) == ' ')
				return (0);
		}
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		ibase;
	int		obase;
	int		n;
	char	*str;

	ibase = check_base(base_from);
	obase = check_base(base_to);
	if (ibase <= 1 || obase <= 1)
		return (0);
	n = ft_atoi(nbr, ibase, base_from);
	str = ft_itoa(n, obase, base_to);
	return (str);
}
