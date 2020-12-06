/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_dic.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 02:00:29 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 02:05:30 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_NUMBER_DIC_H
# define CHECK_NUMBER_DIC_H

int	exact_dic(char **dic, char *str);
int	test_two_digit(char **dic, char *str);
int	test_three_digit(char **dic, char *str);

#endif
