/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:36:18 by hcho              #+#    #+#             */
/*   Updated: 2020/11/24 01:49:50 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int len;
	int f_len;
	int find;

	while(*str)
	{
		if(*str==*to_find)
			find = 1;
			f_len = 0;
			while(*(to_find + f_len))
			{
				if (*(str + len + f_len) != *(to_find + f_len++))
				{
					find = 0;
					break;
				}
				f_len++;
			}
			if(find == 1)
				return (str + len);
		len++;
	}
	return (0);
}

int main()
{
	char a[] = "elephant is a big";
	char a1[] = "elephant is a big";
	char b[] = "hant";
	printf("%s\n%s", strstr(a,b), ft_strstr(a1,b));
	return 0;
}
