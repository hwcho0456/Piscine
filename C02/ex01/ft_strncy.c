/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:42:42 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 10:48:12 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int len;

	len = 0;
	while (*(src + len) )
	{
		if (len < n)
			*dest = *src;
		else
			*dest = '\0';
		len++;
	}
	*(dest + len) = '\0';
	return (dest);
}

int main()
{
	char a1[7];
	char a2[7];
	char b[]="xyzwvu";
	printf("%s\n", strncpy(a1,b,3));
	printf("%s", ft_strncpy(a2,b,3));
	return 0;
}
