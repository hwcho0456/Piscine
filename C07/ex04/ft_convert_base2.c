/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:44:31 by hcho              #+#    #+#             */
/*   Updated: 2020/11/30 14:39:41 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	g_str[12];
int		g_i;

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
	g_str[g_i++] = base[nbr % b_len];
}

char	*ft_itoa(int nbr, int b_len, char *base)
{
	g_i = 0;
	if (nbr < 0)
	{
		g_str[g_i++] = '-';
		rec(-(nbr / b_len), b_len, base);
		g_str[g_i++] = base[-(nbr % b_len)];
	}
	else
	{
		rec(nbr / b_len, b_len, base);
		g_str[g_i++] = base[nbr % b_len];
	}
	g_str[g_i] = '\0';
	return (g_str);
}
