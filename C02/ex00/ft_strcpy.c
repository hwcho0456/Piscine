/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:34:26 by hcho              #+#    #+#             */
/*   Updated: 2020/11/22 07:02:45 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int len;

	len = 0;
	while (*(src + len))
	{
		*(dest = *src;
		len++;
	}
	*(dest + len) = '\n';
	return dest;
}
