/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:16:47 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 09:39:35 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int state;
	int len;

	state = 0;
	len = -1;
	while (*(str + (++len)))
	{
		if (*(str + len) >= '0' && *(str + len) <= '9')
			state = 1;
		else if (*(str + len) >= 'a' && *(str + len) <= 'z' && state == 0)
		{
			state = 1;
			*(str + len) += 'A' - 'a';
		}
		else if (*(str + len) >= 'A' && *(str + len) <= 'Z')
		{
			if (status == 1)
				*(str + len) += 'a' - 'A';
			else
				status = 1;
		}
		else
			status = 0;
	}
	return (str);
}
