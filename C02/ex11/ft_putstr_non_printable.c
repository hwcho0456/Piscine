/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:53:04 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 09:57:53 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char *g_hex;

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void asc_to_hex(int c)
{
    char a;
    char b;

	a = g_hex[c / 16];
	b = g_hex[c % 16];
    write(1, &a, 1);
    write(1, &b, 1);
}
void ft_putstr_non_printable(char *str)
{
	g_hex = "0123456789abcdef";
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
		{
			ft_putchar('\\');
			asc_to_hex((int)*str);
		}
		str++;
	}
}
int main() {
    char a[] = "Coucou\btu vas bien ?";
    ft_putstr_non_printable(a);
    return 0;
}
