/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:31:18 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 19:35:35 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_util.h"
#include "parsing.h"
#include "check_number_dic.h"
#include "print_number_dic.h"
#include "ft_strdup_series.h"
#include "check_str.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define printError write(1,"Dict Error!\n",12);

int g_p;
int g_unit;

int		check_number(char **dic, char *str)
{
	int i;
	char *front;
	char *unit;
	char *back;

	if (exact_dic(dic, str) == 1 || *str == 0)
    {
        free(str);
		return (1);
    }
	else if (ft_strlen(str) == 3)
		return ((test_three_digit(dic, str) == 1) ? 1 : 0);
    else if (ft_strlen(str) == 2)
		return ((test_two_digit(dic, str) == 1) ? 1 : 0);
	else if (ft_strlen(str) >= 4)
	{
	    i = (ft_strlen(str) % 3 == 0) ? 3 : ft_strlen(str) % 3;
        front = ft_strdup_front(str, i);
        unit = ft_strdup_unit(ft_strlen(str) - i + 1);
	    back = ft_strdup_back(str, i);
        free(str);
		return (check_number(dic, front) && check_number(dic, unit) && check_number(dic, back)); 	
	}
    return (0);
}

void	print_number(char **dic, char *str)
{
	int i;
	char *front;
	char *unit;
	char *back;

	if (exact_dic(dic, str) == 1 || *str == 0)
    {
       print_exact_number(dic, str);
       free(str);
    }
	else if (ft_strlen(str) == 3)
		print_three_digit(dic, str);   
    else if (ft_strlen(str) == 2)
        print_two_digit(dic, str);
	else if (ft_strlen(str) >= 4)
	{
		i = (ft_strlen(str) % 3 == 0) ? 3 : ft_strlen(str) % 3;
	    front = ft_strdup_front(str, i);
	    unit = ft_strdup_unit(ft_strlen(str) - i + 1);
	    back = ft_strdup_back(str, i);
		print_number(dic, front);
        print_number(dic, unit);
        print_number(dic, back);
        free(str);
	}
}

void    dic_translate(char *dic_file, char *str)
{
	char    **dictionary;
    char    *pstr;
    int     i;

	dictionary = parsing_dic(dic_file);
	if (!dictionary)
	{
		printError;
		return ;
	}
    pstr = ft_strdup(str);
	if (check_number(dictionary, str) == 1)
    {
        g_p = g_c;
        g_unit = ((ft_strlen(pstr) >= 2) ? 1 : 0);
		print_number(dictionary, pstr);
    }
    else
		printError;
    i = -1;
    while (dictionary[2 * (++i)])
        freetwice(dictionary[2 * i], dictionary[2 * i + 1]);
    free(dictionary);
}

void    translate(char *str)
{
    dic_translate("numbers.dict", str);
}
