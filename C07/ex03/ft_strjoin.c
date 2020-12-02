/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:02:07 by hcho              #+#    #+#             */
/*   Updated: 2020/12/02 23:25:39 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *src)
{
	int len;

	len = 0;
	while (*(src + len))
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int len;
	int i;

	len = ft_strlen(dest);
	i = -1;
	while (*(src + (++i)))
		*(dest + len + i) = *(src + i);
	*(dest + len + i) = '\0';
	return (dest);
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

char	*ft_fillstr(int size, char *dest, char **str, char *sep)
{
	int i;

	ft_strcat(dest, str[0]);
	i = 0;
	while (++i < size)
	{
		ft_strcat(dest, sep);
		ft_strcat(dest, str[i]);
	}
	return (dest);
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char	*dest;
	int		sep_len;
	int		str_len;

	if (size == 0)
	{
		dest = (char *)malloc(sizeof(char));
		*dest = '\0';
		return (dest);
	}
	str_len = 0;
	i = -1;
	while (++i < size)
		str_len += ft_strlen(str[i]);
	sep_len = ft_strlen(sep);
	dest = (char *)malloc(sizeof(char) * (str_len + sep_len * (size - 1) + 1));
	if (!dest)
		return (0);
	initialize(dest);
	ft_fillstr(size, dest, str, sep);
	return (dest);
}
