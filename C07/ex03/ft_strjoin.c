/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:02:07 by hcho              #+#    #+#             */
/*   Updated: 2020/11/30 20:08:51 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int		*ft_strlen(char *src)
{
	int len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

void	initialize(char *src)
{
	int len;

	len = 0;
	while (*(src + len))
	{
		*(src + len) = '\0';
		len++;
	}
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char	*dest;
	int		sep_len;
	int		str_len;
	int		i;
	int		j;

	if (size == 0)
		return (0);
	str_len = 0;
	i = -1;
	while (++i < size)
		str_len += ft_strlen(str[i]);
	sep_len = ft_strlen(sep);
	dest = (char *)malloc(sizeof(char) * (str_len + sep_len * (size - 1)));
	if (!dest)
		return (0);
	initialize(dest);
	ft_strcat(dest, str[0]);
	i = 0;
	while (++i < size)
	{
		ft_strcat(dest, sep);
		ft_strcat(dest, str[i]);
	}
	return (dest);
}
