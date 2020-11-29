/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:55:49 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 15:31:29 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "ft_maps.h"

int	main(int argc, char *argv[])
{
	int **condition;
	int i;
	int n;

	if (argc == 2)
	{
		n = validate_input(argv[1]);
		condition = process_input(argv[1], n);
		if (condition == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		rush(condition, n);
		i = -1;
		while (++i < 4)
			free(condition[i]);
		free(condition);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
