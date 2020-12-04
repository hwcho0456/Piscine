/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:10:00 by hcho              #+#    #+#             */
/*   Updated: 2020/12/04 22:31:10 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translate.h"
#include "read_dic.h"

int main(int argc, char *argv[])
{
    if (argc == 2)
        translate(argv[1]);
    else if (argc == 3)
        dic_translate(argv[2], argv[1]);
    else if (argc == 1)
        print_dic();
    return (0);
}
