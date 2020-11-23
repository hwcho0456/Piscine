/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:41:53 by hcho              #+#    #+#             */
/*   Updated: 2020/11/24 04:59:32 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int d_len;
	unsigned int len;

	d_len = 0;
	len = 0;
	while (dest[d_len] != '\0')
		d_len++;
	while ((src[len] != '\0') && size > 1)
	{
		dest[d_len + len] = src[len];
		len++;
		size--;
	}
	if (size > 0)
		dest[len] = '\0';
	return (d_len);
}
