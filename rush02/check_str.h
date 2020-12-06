/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:21:41 by sunbchoi          #+#    #+#             */
/*   Updated: 2020/12/06 12:42:28 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_STR_H
# define CHECK_STR_H

int g_c;
int	check_onlynumber(char *str);
int		count_colon(char *str);
int		check_space(char *str);
int		check_num_space(char *str);
int		check_printable(char *str);

#endif
