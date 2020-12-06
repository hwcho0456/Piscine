/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:31:15 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 04:35:54 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "str_util.h"
#include "check_str.h"
#include "ft_split.h"

int		file_len(char *file)
{
	int		fd;
	char	c;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	else
	{
		len = 0;
		while (read(fd, &c, 1))
			len++;
		close(fd);
	}
	return (len);
}

char	*read_file(char *file)
{
	int		fd;
	int		len;
	char	*file_str;

	len = file_len(file);
	file_str = (char *)malloc(sizeof(char) * len);
	if (!file_str)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		read(fd, file_str, len);
		close(fd);
	}
	return (file_str);
}

int		check_dic_line(char *file_line)
{
	int		valid;
	char	**line_split;
	int		split_count;

	if (check_space(file_line) == 1)
		return (1);
	valid = 1;
	if (count_colon(file_line) != 1)
		return (0);
	split_count = str_split_count(file_line, ":");
	if (split_count != 2)
		return (0);
	line_split = ft_split(file_line, ":");
	if (check_num_space(line_split[0]) == 0)
		valid = 0;
	if (check_printable(line_split[1]) == 0)
		valid = 0;
	free(line_split[0]);
	free(line_split[1]);
	free(line_split);
	return (valid == 1) ? (1) : (0);
}

int		check_dic(char *file)
{
	char	*file_str;
	char	**file_line;
	int		i;
	int		valid;

	file_str = read_file(file);
	if (!file_str)
		return (0);
	file_line = ft_split(file_str, "\n");
	if (!file_line)
		return (0);
	i = 0;
	valid = 1;
	while (file_line[i])
	{
		if (!check_dic_line(file_line[i]))
			valid = 0;
		free(file_line[i]);
		i++;
	}
	free(file_str);
	free(file_line);
	if (valid == 0)
		return (0);
	return (1);
}
