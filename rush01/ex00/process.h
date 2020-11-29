/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:53:32 by hcho              #+#    #+#             */
/*   Updated: 2020/11/29 15:51:56 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

int		validate_input(char *str);
int		**initialize_condition(int n);
void	assign_condition(int *i, int *j, int n);
int		**save_input(int **condition, int n, char *str);
int		**process_input(char *str, int n);

#endif
