/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:41:17 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 21:17:02 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int len;
	
	len = 0;
	while(*(s1 + len) == *(s2 + len) && *(s1 + len) && *(s2 + len) && len < n)
		len++;
	return (*(s1 + len) - *(s2 + len));
}

int main()
{
	char a[]="abcdefg";
	char b[]="abcde";
	printf("%d %d\n", strncmp(a,b,7), ft_strncmp(a,b,7));
	return 0;
}
