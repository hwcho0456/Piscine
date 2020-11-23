/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:40:52 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 19:45:38 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int len;

	len = 0;
	while (*(src + len))
	{
		if (len < size - 1)
			*(dest + len) = *(src + len);
		else
			*(dest + len) = '\0';
		len++;
	}
	*(dest + len) = '\0';
	return (len);
}
