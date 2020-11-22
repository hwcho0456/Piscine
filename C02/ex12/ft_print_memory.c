/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:58:27 by hcho              #+#    #+#             */
/*   Updated: 2020/11/23 00:10:37 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_hex;
char g_substr[16];

void    print_addr(long long addr, int span) // 한 줄의 맨 앞 문자의 주소를 출력, span : 주소의 출력할 길이
{
    char a;

    if (addr == 0)
    {
        while (span-- > 0)
            write(1, "0", 1); // 남은 공간만큼 0으로 채워줌
        return ;
    }
    print_addr(addr / 16, span - 1);
    a = g_hex[addr % 16];
    write(1, &a, 1);
}

void    decode_line(unsigned char *ptr, int len) // 문자열 아스키코드 값 출력 & .으로 대체된 문자열 저장
{
    int i;
    char a;
    char b;

    i = -1;
    while (++i < 16)
    {
        if (i % 2 == 0)
            write(1, " ", 1);
        if (i < len)
        {
            *(g_substr + i) = (' ' <= *(ptr + i) && *(ptr + i) <= '~') ? *(ptr + i) : '.'; // 출력불가능 문자열 .으로 대체
            a = g_hex[*(ptr + i) / 16];
            b = g_hex[*(ptr + i) % 16];
            write(1, &a, 1);
            write(1, &b, 1);
        }
        else
            write(1, "  ", 2); // 그 줄에 문자가 더이상 없으면 아스키코드 값 대신 공백 출력
    }
}

void    *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int i;
    int len;
    unsigned char *ptr;

    g_hex = "0123456789abcdef"; // 16진수 표현용 
    i=0;
    while (size != 0) 
    {
        len = (size >= 16) ?  16 :  size;
        ptr = (unsigned char*)addr + i;
        print_addr((long long)ptr, 16); // 첫 문자의 주소 출력 
        write(1, ":", 1);
        decode_line(ptr, len);
        write(1, " ", 1);
        write(1, g_substr, len); // 대체된 문자열 출력
        write(1, "\n", 1);
        size -= len;
        i += 16; // 16 글자씩 묶어서 한줄
    }
    return (addr);
}

int main(void)
{
    char str[]="abcdefghijklnmopqrstuvwxyz";
    ft_print_memory(str,26);
    return 0;
}
