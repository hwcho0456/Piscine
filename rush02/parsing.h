/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 02:17:20 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 02:19:11 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

char	*eliminate_space(char *str);
int	count_except_space(char **strs);
char	**copy_except_space(char **file_line);
char	**parsing_dic(char *dic);

#endif
