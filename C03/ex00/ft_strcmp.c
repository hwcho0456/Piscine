/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:48:36 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 20:40:47 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int len;
	
	len = 0;
	while((*(s1 + len) == *(s2 + len)) && *(s1 + len) && *(s2 + len))
	   len++;
	return (*(s1 + len) - *(s2 + len));
}

int main()
{
	char a[]="abcdefg";
	char b[]="abc";
	printf("%d\n",ft_strcmp(a,b));
	printf("%d\n", strcmp(a,b));
	return 0;
}
	
