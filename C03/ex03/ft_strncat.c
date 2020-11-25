/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:25:31 by hcho              #+#    #+#             */
/*   Updated: 2020/11/25 10:50:44 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (*(dest + len))
		len++;
	while (*(src + i) && i < nb)
	{
		*(dest + len + i) = *(src + i);
		i++;
	}
	*(dest + len + i) = '\0';
	return (dest);
}
