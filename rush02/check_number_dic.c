/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_dic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 20:28:05 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 15:54:19 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str_util.h"
#include "check_str.h"
#include "print_number_dic.h"

int	exact_dic(char **dic, char *str)
{
	int i;

	i = 0;
	while (dic[2 * i])
	{
		if (ft_strcmp(dic[2 * i], str) == 0)
        {
            g_c++;
			return (1);
        }
		i++;
	}
	return (0);
}

char    *malloc_and_setnull(int i)
{
    char *dest;

    dest = (char *)malloc(sizeof(char) * i);
    dest[i - 1] = '\0';
    return (dest);
}

int	test_two_digit(char **dic, char *str)
{
    char *dest;
    int  valid;

	if (exact_dic(dic,str) == 1)
	{
		free(str);
		return (1);
	}
    valid = 1;
    dest = malloc_and_setnull(3);
	if (str[0] != '0')
	{
        dest[0] = str[0];
        dest[1] = '0';
		valid =  (exact_dic(dic, dest) != 1) ? 0 : valid;
	} 
    free(dest);
    dest = malloc_and_setnull(2);
	if (str[1] != '0')
	{
        dest[0] = str[1];
		valid = (exact_dic(dic, dest) != 1) ? 0 : valid;
	}
	freetwice(str, dest); 
	return ((valid == 1) ? 1 : 0);
}

int	test_three_digit(char **dic, char *str)
{
	char *dstr;
    char *dest;

    dest = (char *)malloc(sizeof(dest) * 2);
    dest[1] = '\0';
	if (exact_dic(dic, str) == 1)
	{
		free(str);
		return (1);
	}
	if (str[0] != '0')
	{
        dest[0] = str[0];
		if (exact_dic(dic, dest) == 0 || exact_dic(dic, "100") == 0)
		{
			free(str);
			return (0);
		}
	}
	dstr = (char *)malloc(sizeof(char) * 3);
	dstr[0] = str[1];
	dstr[1] = str[2];
	dstr[2] = '\0';
    free(dest);
	free(str);
	return (test_two_digit(dic, dstr));
}
