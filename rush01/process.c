#include <stdlib.h>
#include <stdio.h>

int validate_input(char *str)
{
    int count;
    int state;
    int len;

    state = 0;
    count = 0;
    len = 0;
    while(*(str + len))
    {
        if(*(str + len) != ' ' && *(str + len) < '0' || *(str + len) > '9')
            return (-1);
        else if(*(str + len) == ' ')
            state = 0;
        else
        {
            if ( state == 0)
            {
                state = 1;
                count++;
            }
        }
        len++;
    }
    if (count % 4 != 0)
        return (-1);
    else 
        return (count / 4);
}

int **process_input(char *str)
{   
    int **condition;
    int state;
    int n;
    int i;
    int j;
    int count;
    
    n = validate_input(str);
    if ( n == -1)
        return NULL;
    condition = (int **)malloc(sizeof(int *) * 4);
    if(!condition)
        return NULL;
    i = -1;
    while(++i < 4)
    {
        condition[i]=(int *)malloc(sizeof(int) * n);
        if (!condition[i])
        {
            while(--i >= 0)
                free(condition);
            return NULL;
        }
    }        
    i = 0;
    j = -1;
    while(*str)
    {
        if(*str == ' ')
            state = 0;
        else
        {
            if ( state == 0)
            {
                j++;
                if ( j == n)
                {
                    i++;
                    j = 0;
                }
                state = 1;
                condition[i][j] = *str - '0';
                count++;
            }
            else
                condition[i][j] = 10 *condition[i][j] + *str -'0';
        }
        str++;
    }
    return condition;
}
