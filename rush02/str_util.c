/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:34:04 by hcho              #+#    #+#             */
/*   Updated: 2020/12/04 22:40:51 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while(*(str + len))
        len++;
    return (len);
}

void    ft_putstr(char *str)
{
    int len;

    len = 0;
    while(*(str + len))
        write(1, str+(len++), 1);
}
