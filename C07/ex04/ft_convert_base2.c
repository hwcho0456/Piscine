/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:44:31 by hcho              #+#    #+#             */
/*   Updated: 2020/12/02 10:23:00 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	g_str[40];
int		g_i;

void	initialize(void)
{
	int i;

	i = 0;
	while (++i < 40)
		g_str[i] = 0;
}

char	*ft_strcat(char *dest, char *src)
{
	int len;

	len = 0;
	while (*(dest + len))
		len++;
	while (*src)
		*(dest + len++) = *(src++);
	*(dest + len) = '\0';
	return (dest);
}

void	rec(int nbr, int b_len, char *base)
{
	if (nbr == 0)
		return ;
	rec(nbr / b_len, b_len, base);
	g_str[++g_i] = base[nbr % b_len];
}

char	*ft_itoa(int nbr, int b_len, char *base)
{
	initialize();
	g_i = -1;
	if (nbr < 0)
	{
		g_str[++g_i] = '-';
		rec(-(nbr / b_len), b_len, base);
		g_str[++g_i] = base[-(nbr % b_len)];
	}
	else
	{
		rec(nbr / b_len, b_len, base);
		g_str[++g_i] = base[nbr % b_len];
	}
	g_str[++g_i] = '\0';
	return (g_str);
}
