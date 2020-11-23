/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:40:52 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 09:41:20 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    int i;
    i = 0;
    while (*(src + i) && i < size - 1)
    {
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest + i) = '\0';
    return (size-1);
}
int main() {
    char a[] = "ewajflkdsf";
    char b[] = "aaaaaaaaaaaaaaaaaaaaaa";
    printf("%s\n", a);
    int i = ft_strlcpy(a, b, 6);
    printf("%d\n", i);
    printf("%s", a);
    return 0;
}
