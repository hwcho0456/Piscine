/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:25:31 by hcho              #+#    #+#             */
/*   Updated: 2020/11/24 01:35:36 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int len;

	len = 0;
	while(*(dest + len))
		len++;
	while(*(src) || nb-- > 0)
		*(dest + len++) = *(src++);
	*(dest + len) = '\0';
	return dest;
}

int main()
{
	char a[20] = "abcdf";
	char a1[20] = "abcdf";
	char b[10] = "xyz";
	printf("%s\n%s", strncat(a,b,7), ft_strncat(a1,b,7));
	return 0;
}
