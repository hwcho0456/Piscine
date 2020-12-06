/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:05:16 by sunbchoi          #+#    #+#             */
/*   Updated: 2020/12/06 02:29:40 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTIL_H
# define STR_UTIL_H

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
int		str_split_count(char *str, char *charset);

#endif
