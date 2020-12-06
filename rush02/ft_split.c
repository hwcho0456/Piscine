/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:59:52 by hcho              #+#    #+#             */
/*   Updated: 2020/12/02 19:01:14 by hcho             ###   ########.fr       */
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
	words = (char **)malloc(sizeof(char *) * (count + 1));
	return (words);
}

char	*str_rangecopy(char *str, char *charset, int start)
{
	char	*dest;
	int		len;
	int		i;

	len = start;
	while (*(str + len) && !str_in_charset(*(str + len), charset))
		len++;
	dest = (char *)malloc(sizeof(char) * (len - start + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i + start < len)
	{
		*(dest + i) = *(str + start + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

void	fill_words(char **words, char *str, char *charset)
{
	int		len;
	int		state;
	int		n;
	int		i;

	len = -1;
	state = 0;
	n = -1;
	i = 0;
	while (*(str + (++len)))
	{
		if (str_in_charset(*(str + len), charset))
			state = 0;
		else if (state == 0)
		{
			i = len;
			words[++n] = str_rangecopy(str, charset, i);
			state = 1;
		}
	}
	words[++n] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**words;

	words = str_count(str, charset);
	fill_words(words, str, charset);
	return (words);
}
