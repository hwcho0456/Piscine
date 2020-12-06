/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:34:04 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 02:54:20 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_split.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
		write(1, str + (len++), 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int len;

	len = 0;
	while ((*(s1 + len) == *(s2 + len)) && *(s1 + len) && *(s2 + len))
		len++;
	return (*(s1 + len) - *(s2 + len));
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	while (*(src + len))
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

int		str_split_count(char *str, char *charset)
{
	int		state;
	int		count;
	int		len;

	state = 0;
	count = 0;
	len = 0;
	while (*(str + len))
	{
		if (str_in_charset(*(str + len), charset))
			state = 0;
		else
		{
			if (state == 0)
				count++;
			state = 1;
		}
		len++;
	}
	return (count);
}
