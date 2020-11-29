/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condtion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:35:38 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 14:33:46 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_CONDITION_H
# define CHECK_CONDITION_H

int		check_initial_condition(int **condition, int n);
int		check_line_condition(int **maps, int line, int n, int **condition);
int		check_final_condition(int **maps, int n, int **condition);

#endif
