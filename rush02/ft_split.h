/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:22:03 by sunbchoi          #+#    #+#             */
/*   Updated: 2020/12/06 02:04:53 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

int		str_in_charset(char c, char *charset);
char	**str_count(char *str, char *charset);
char	*str_rangecopy(char *str, char *charset, int start);
void	fill_words(char **word, char *str, char *charset);
char	**ft_split(char *str, char *charset);

#endif
