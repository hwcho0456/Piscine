/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_series.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:17 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 19:48:48 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str_util.h"
#include "translate.h"
		
char	*ft_strdup_front(char *str, int i)
{
	int		len;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (i + 1));
	len = 0;
	while (len < i)
	{
		*(dest + len) = *(str + len);
		len++;
	}
	*(dest + len) = '\0';
    g_unit = 0;
	return (dest);
}

char	*ft_strdup_unit(int i)
{
	int		len;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (i + 1));
	dest[0] = '1';
	len = 1;
	while (len < i)
	{
		*(dest + len) = '0';
		len++;
	}
	*(dest + len) = '\0';
	return (dest);
}

char	*ft_strdup_back(char *str, int i)
{
	int		len;
	char	*dest;
	int 	frontzero;

	len = i;
	frontzero = 0;
	while (*(str + len) == '0')
	{
		frontzero++;
		len++;
    }
    g_unit = 1;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i - frontzero + 1));
	len = 0;
	while (*(str + i + frontzero + len))
	{
		*(dest + len) = *(str + i + frontzero + len);
		len++;
	}
	*(dest + len) = '\0';
	return (dest);
}
