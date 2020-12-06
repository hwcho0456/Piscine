/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 02:23:17 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 19:10:09 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATE_H
# define TRANSLATE_H

int g_p;
int g_unit;
void    translate(char *str);
void    dic_translate(char *dic_file, char *str);
int		check_number(char **dic, char *str);
void	print_number(char **dict, char *str);

#endif
