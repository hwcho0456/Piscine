/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 02:07:00 by hcho              #+#    #+#             */
/*   Updated: 2020/12/06 02:08:05 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRJOIN_H
# define FT_STRJOIN_H

char	*ft_strcat(char *dest, char *src);
void	initialize(char *src);
char	*ft_fillstr(int size, char *dest, char **str, char *sep);
char	*ft_strjoin(int size, char **str, char *sep);

#endif
