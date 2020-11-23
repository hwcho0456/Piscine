/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:42:42 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 22:00:02 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int len;

	len = 0;
	while (*(src + len))
	{
		if (len < n)
			*(dest + len) = *(src + len);
		len++;
	}	
	while(len < n)
	{
		*(dest + len) = '\0';
		len++;
	}
	return (dest);
}
