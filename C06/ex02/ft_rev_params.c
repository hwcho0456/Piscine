/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 08:42:15 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 20:37:50 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int n;

	n = argc - 1;
	while (n > 0)
	{
		while (*argv[n])
		{
			write(1, argv[n], 1);
			argv[n]++;
		}
		write(1, "\n", 1);
		n--;
	}
	return (0);
}
