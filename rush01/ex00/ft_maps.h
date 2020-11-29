/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:35:06 by jeson             #+#    #+#             */
/*   Updated: 2020/11/29 15:33:57 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAPS_H
# define FT_MAPS_H

int g_find;
int g_factorial_n;

void	freemaps(int **maps, int n);
int		**initialize_map(int n);
void	print_map(int **maps, int n);
void	dfs(int **maps, int line, int n, int **condition);
void	rush(int **condition, int n);

#endif
