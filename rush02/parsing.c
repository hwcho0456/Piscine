/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 10:03:09 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 05:43:57 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_split.h"
#include "ft_strjoin.h"
#include "str_util.h"
#include "check_str.h"
#include "file_util.h"

char	*eliminate_space(char *str)
{
	int		i;
	int		count;		
	char	**words;
	char	*dest;

	count = str_split_count(str, " ");
	words = ft_split(str, " ");
	dest = ft_strjoin(count, words, " ");
	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (dest);
}

int	count_except_space(char **strs)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(strs[i])
	{
		if (check_space(strs[i]) == 0)
			count++;
        i++;
	}
	return (count);
}

char	**copy_except_space(char **file_line)
{
	int i;
	int j;
	int count;
	char **line_split;
	char **dictionary;

    count = count_except_space(file_line);
	dictionary = (char **)malloc(sizeof(char *) * (2 * count + 1));
	i = 0;
	j = 0;
    while (i < count)
	{
		while (check_space(file_line[j]) == 1)
		{
			j++;
		}
		line_split = ft_split(file_line[j], ":");
		dictionary[2 * i] = eliminate_space(line_split[0]);
		dictionary[2 * i + 1] = eliminate_space(line_split[1]);
		j++;
		i++;
	}
	dictionary[2 * i] = 0;
	return (dictionary);
}

char	**parsing_dic(char *dic)
{
	int		i;
	char	**file_line;
	char	**dictionary;

	if (check_dic(dic) == 0)
		return (0);
	file_line = ft_split(read_file(dic), "\n");
	if (!file_line)
        return (0);
	dictionary = copy_except_space(file_line);
	i = 0;
	while (file_line[i])
	{
		free(file_line[i]);
		i++;
	}
	free(file_line);
	return (dictionary);
}
