/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:59:52 by hcho              #+#    #+#             */
/*   Updated: 2020/12/02 10:54:40 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_in_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (*(charset + i))
	{
		if (*(charset + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	**str_count(char *str, char *charset)
{
	char	**words;
	int		state;
	int		count;
	int		len;

	state = 0;
	count = 0;
	len = 0;
	while (*(str + len))
	{
		if (str_in_charset(*(str + len), charset))
			state = 0;
		else
		{
			if (state == 0)
				count++;
			state = 1;
		}
		len++;
	}
	words = (char **)malloc(sizeof(char *) * count);
	return (words);
}

char	*str_rangecopy(char *str, int start, int end)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < end - start)
	{
		*(dest + i) = *(str + start + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

void	set_variables(int *len, int *n, int *state, int *i)
{
	*len = -1;
	*n = -1;
	*state = 0;
	*i = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		len;
	int		state;
	int		n;
	int		i;

	words = str_count(str, charset);
	set_variables(&len, &n, &state, &i);
	while (*(str + (++len)))
	{
		if (str_in_charset(*(str + len), charset))
		{
			if (state == 1)
				words[++n] = str_rangecopy(str, i, len);
			state = 0;
		}
		else
		{
			if (state == 0)
				i = len;
			state = 1;
		}
	}
	words[++n] = str_rangecopy(str, i, len);
	return (words);
}
