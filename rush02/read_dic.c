/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:37:21 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 04:52:13 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_util.h"
#include "str_util.h"
#include <unistd.h>

# define printError write(1,"DicError!\n",10);

void	print_dic(void)
{
    char *file_str;

    if  (check_dic("numbers.dict") == 0)
    {
        printError;
        return;
    }
    file_str = read_file("numbers.dict");
    ft_putstr(file_str);
}
