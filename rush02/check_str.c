/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:41:39 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 12:42:20 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_util.h"

int g_c;

int	check_onlynumber(char *str)
{
	int len;

    g_c = 0;
	len = 0;
    if (*(str + len) == '0' && ft_strlen(str) != 1)
    {
        return (0);
    }
	while (*(str + len))
	{
		if (*(str + len) < '0' || *(str + len) > '9')
			return (0);
        len++;
	}
	return (1);
}

int	count_colon(char *str)
{
	int count;
	int len;

	count = 0;
	len = 0;
	while (*(str + len))
	{
		if (*(str + len) == ':')
			count++;
		len++;
	}
	return (count);
}

int	check_space(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
	{
		if (*(str + len) != ' ')
			return (0);
		len++;
	}
	return (1);
}

int	check_num_space(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
	{
		if ((*(str + len) < '0' || *(str + len) > '9') && *(str + len) != ' ')
			return (0);
		len++;
	}
	return (1);
}

int	check_printable(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
	{
		if (*(str + len) < 32 || *(str + len) > 126)
			return (0);
		len++;
	}
	return (1);
}
