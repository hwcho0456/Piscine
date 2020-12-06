/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:10:00 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 13:28:29 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "str_util.h"
#include "translate.h"
#include "check_str.h"
#include "read_dic.h"

# define printError write(1,"Dict Error!\n",12);

int main(int argc, char *argv[])
{
    char *num;

    if (argc == 1)
        print_dic();
	else if ((argc == 2 || argc == 3))
    {  
        if (check_onlynumber(argv[1]) == 1)
        {   
            num = ft_strdup(argv[1]);
            if (argc == 2)
        	    translate(num);
		    else
        	    dic_translate(argv[2], argv[1]);
        }
        else
            write(1, "Error\n", 6);
    }
    else
        printError;
    return (0);
}
