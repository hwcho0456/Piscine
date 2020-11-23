/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:40:52 by hcho              #+#    #+#             */
/*   Updated: 2020/11/24 01:05:50 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int s_len;
	unsigned int len;

	s_len = 0;
	len = 0;
	while (*src)
		s_len++;
	while (*(src + len) && len < size - 1)
	{
		*(dest + len) = *(src + len);
		len++;
	}
	if (size > 0)
		*(dest + len) = '\0';
	return (s_len);
}
