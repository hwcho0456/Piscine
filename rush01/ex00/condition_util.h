/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:18:32 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 14:32:49 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITION_UTIL_H
# define CONDITION_UTIL_H

int		see_left_line(int **maps, int line, int n);
int		see_right_line(int **maps, int line, int n);
int		check_overlap(int **maps, int line, int n);
int		see_up_column(int **maps, int col, int n);
int		see_down_column(int **maps, int col, int n);

#endif
