/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 05:41:15 by hcho              #+#    #+#             */
/*   Updated: 2020/11/19 05:48:34 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include stdio.h

void    ft_putchar(char c) 
{
	write(1, &c, 1);
}

void    ft_print_numbers(void)
{
	int n;
	n=0;
	
	while(n<10)
	{
		ft_putchar(n);
		n++;
	}
}

int   main(void)
{
	ft_print_numbers(void);
	return 0;
}
