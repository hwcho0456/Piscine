/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:21:20 by sunbchoi          #+#    #+#             */
/*   Updated: 2020/12/05 16:24:05 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_UTIL_H
# define FILE_UTIL_H

int		file_len(char *file);
char	*read_file(char *file);
int		check_dic_line(char *file_line);
int		check_dic(char *file);
void	ft_putstr(char *str);

#endif
