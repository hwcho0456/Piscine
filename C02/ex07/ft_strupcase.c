/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 06:42:59 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 11:17:03 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int gap;
	int len;

	len = 0;
	gap = 'A' - 'a';
	while (*(str + len))
	{
		if (*(str + len) >= 'a' && *(str + len) <= 'z')
			*(str + len) += gap;
		len++;
	}
	return (str);
}
