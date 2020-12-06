/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_dic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 00:16:24 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 16:06:48 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_number_dic.h"
#include "str_util.h"
#include "check_str.h"
#include "translate.h"
#include <stdlib.h>
#include <unistd.h>

void	print_exact_number(char **dic, char *str)
{
	int i;

	i = 0;
	while (dic[2 * i])
	{
		if (ft_strcmp(dic[2 * i], str) == 0)
        {
            g_p--;
			write(1, dic[2 * i + 1], ft_strlen(dic[2 * i + 1]));
            (g_p != 0) ? write(1, " ", 1) : write(1, "\n", 1);
        }
		i++;
	}
}

void    freetwice(char *dest, char *str)
{
    free(dest);
    free(str);
}

void	print_two_digit(char **dic, char *str)
{
    char *dest;

	if (exact_dic(dic, str) == 1)
	{
        print_exact_number(dic, str);
        free(str);
        return ;
	}
    dest = (char *)malloc(sizeof(char) * 3);
    dest[2] = '\0';
	if (str[0] != '0')
	{
        dest[0] = str[0];
        dest[1] = '0';
		print_exact_number(dic, dest);
	}
    free(dest);
    dest = (char *)malloc(sizeof(char) * 2);
    dest[1] = '\0';
	if (str[1] != '0')
    {
        dest[0] = str[1];
		print_exact_number(dic, dest);
    }
    freetwice(dest, str);
}

void	print_three_digit(char **dic, char *str)
{
	char *dstr;
    char *dest;

	if (exact_dic(dic, str) == 1)
	{
        print_exact_number(dic, str);
        free(str);
        return ;
	}
    dest = (char *)malloc(sizeof(char) * 2);
    dest[1] = '\0';
	if (str[0] != '0')
	{
        dest[0] = str[0];
		print_exact_number(dic, dest);
        print_exact_number(dic, "100");
	}
	dstr = (char *)malloc(sizeof(char) * 3);
	dstr[0] = str[1];
	dstr[1] = str[2];
	dstr[2] = '\0';
    free(dest);
	free(str);
	print_two_digit(dic, dstr);
}

