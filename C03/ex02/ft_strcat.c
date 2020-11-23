/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:17:55 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 22:10:01 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int len;

	len = 0;
	while(*(dest + len))
		len++;
	while(*src)
		*(dest + len++) = *(src++);
	*(dest + len) = '\0';
	return dest;
}

int main()
{
	char a[] = "abcde\0\0\0\0\0\0\0\0\0";
	char a1[] = "abcde\0\0\0\0\0\0\0\0\0";
	char b[] = "xyzw";
	printf("%s\n%s", strcat(a1,b),ft_strcat(a,b));
	return 0;
}
