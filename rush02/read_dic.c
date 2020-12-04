/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:37:21 by hcho              #+#    #+#             */
/*   Updated: 2020/12/04 22:48:16 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "str_util.h"

void    read_dic(void)
{
    int fd;
    int check;
    char c;

    fd = open("numbers.dic", O_RDONLY);
    if (fd == -1)
        printError;
    else
    {
        while(check = read(fd, &c, 1))
            write(1, &c, 1);
        close(fd);
    }
}
