/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:58:27 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 20:20:32 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_hex;

void	print_addr(unsigned int addr, int span)
{
	if (addr == 0)
	{
		while (span-- > 0)
			write(1, "0", 1);
		return ;
	}
	print_addr(addr / 16, span - 1);
	write(1, &g_hex[addr % 16], 1);
}

void	decode_line(unsigned char *ptr, int len)
{
	int		i;
	char	substr[16];

	i = -1;
	write(1, ":", 1);
	while (++i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i < len)
		{
			if (*(ptr + i) >= 32 && *(ptr + i) <= 126)
				*(substr + i) = *(ptr + i);
			else
				*(substr + i) = '.';
			write(1, &g_hex[*(ptr + i) / 16], 1);
			write(1, &g_hex[*(ptr + i) % 16], 1);
		}
		else
			write(1, "  ", 2);
	}
	write(1, " ", 1);
	write(1, substr, len);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	len;
	int				line_len;
	unsigned char	*ptr;

	g_hex = "0123456789abcdef";
	len = 0;
	while (len < size)
	{
		line_len = (size - len >= 16) ? 16 : size - len;
		ptr = (unsigned char*)addr + len;
		print_addr((unsigned int)ptr, 16);
		decode_line(ptr, line_len);
		len += line_len;
	}
	return (addr);
}
