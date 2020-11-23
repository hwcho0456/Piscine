/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:41:53 by hcho              #+#    #+#             */
/*   Updated: 2020/11/24 05:56:48 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int s_len;
	unsigned int d_len;
	unsigned int len;

	d_len = 0;
	s_len = 0;
	len = 0;
	while (src[s_len] != '\0')
		s_len++;
	while (dest[d_len] != '\0')
		d_len++;
	while ((src[len] != '\0') && size > 1)
	{
		dest[d_len + len] = src[len];
		len++;
		size--;
	}
	if (size > 0)
	{
		dest[len] = '\0';
		return (s_len + size);
	}
	return (s_len);
}
