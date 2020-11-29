#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define printError write(1, "Error\n", 6)

int g_find;
int factorial_n;

int factorial(int n)
{
    int p;
    int answer;

    if (n < 0)
        return (0);
    if (n == 0)
        return (1);
    p = n + 1;
    answer = 1;
    while (--p > 0)
        answer = answer * p;
    return answer;
}

void    freemaps(int **maps, int n)
{
    int i;

    i = -1;
    while(++i < n)
        free(maps[i]);
    free(maps);
}
void    swap(int *arr, int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void    permutation(int *line_map, int i, int n)
{       
    int j;
    int k;

    j = n;
    while(--j > 0)
    {
        k = i / factorial(j);
        swap(line_map, n - j - 1, n - j + k - 1); 
        i = i % factorial(j); 
    }
}

int **intialize_map(int n)
{
    int **maps;
    int success;
    int i;
    int j;

    maps = (int **)malloc(sizeof(int *) * n);
    if (!maps)
        return (0);
    i = -1;
    success = 1;
    while (++i < n)
    {
        maps[i] = (int *)malloc(sizeof(int) * n);
        if (!maps[i])
        {
            success = 0;
            break;
        }
        j = -1;
        while (++j < n)
            maps[i][j] = j + 1;
    }
    if (success == 0)
    {
        while(--i>=0)
            free(maps[i]);
        free(maps);
    }
    return maps;
}

void    reset_line(int *line, int n)
{
    int i;

    i = -1;
    while (++i < n)
        line[i] = i + 1;
}

int check_initial_condition(int **condition, int n)
{
    int i;

    i = -1;
    while (++i < n)
    {
        if (condition[0][i] <= 0 || condition[1][i] <= 0)
            return (0);
        if (condition[2][i] <= 0 || condition[3][i] <= 0)
            return (0);
        if (condition[0][i] + condition[1][i] > n + 1)
            return (0);        
        if (condition[2][i] + condition[3][i] > n + 1)
            return (0);
    }
    return (1);
}

int see_left_line(int **maps, int line, int n)
{
    int j;
    int max;
    int count;

    j = -1;
    max = 0;
    count = 0;
    while (++j < n)
    {
        if(max < maps[line][j])
        {
            count++;
            max = maps[line][j];
        }
    }
    return (count);
}

int see_right_line(int **maps, int line, int n)
{
    int j;
    int max;
    int count;

    j = n;
    max = 0;
    count = 0;
    while (--j >= 0)
    {
        if(max < maps[line][j])
        {
            count++;
            max = maps[line][j];
        }
    }
    return (count);
}

int check_overlap(int **maps, int line, int n)
{
    int i;
    int j;

    j = -1;
    while(++j < n)
    {
        i = -1;
        while(++i < line)
        {
            if (maps[line][j] == maps[i][j])
                return (0);
        }
    }
    return (1);
}

int check_line_condition(int **maps, int line, int n, int **condition)
{
    if (see_left_line(maps, line, n) != condition[2][line])
        return (0);
    if (see_right_line(maps, line, n) != condition[3][line])
        return (0);
    if (check_overlap(maps, line, n) == 0)
        return (0);
    return (1);
}

int see_up_column(int **maps, int col, int n)
{
    int i;
    int max;
    int count;

    i = -1;
    max = 0;
    count = 0;
    while (++i < n)
    {
        if(max < maps[i][col])
        {
            count++;
            max = maps[i][col];
        }
    }
    return (count);
}

int see_down_column(int **maps, int col, int n)
{
    int i;
    int max;
    int count;

    i = n;
    max = 0;
    count = 0;
    while (--i >= 0)
    {
        if(max < maps[i][col])
        {
            count++;
            max = maps[i][col];
        }
    }
    return (count);
}

int check_final_condition(int **maps, int n, int **condition)
{
    int j;

    j = -1;
    while(++j < n)
    {
        if (see_up_column(maps, j, n) != condition[0][j])
            return (0);        
        if (see_down_column(maps, j, n) != condition[1][j])
            return (0);
    }
    return (1);
}

void    print_map(int **maps, int n)
{
    int i;
    int j;
    char digit;
    char digit2;

    i = -1;
    while (++i < n)
    {
        j = -1;
        while(++j < n)
        {
            if (n < 10)
            {
                digit = maps[i][j] + '0';
                write(1, &digit, 1);
                write(1, " ", 1);
            }
            else
            {                
                digit = maps[i][j] / 10 + '0';
                digit2 = maps[i][j] % 10 + '0';
                (digit == '0') ? write(1, " ", 1) : write(1, &digit, 1);
                write(1, &digit2, 1);
                write(1, " ", 1);      
            }
        }
        write(1, "\n", 1);
    }
}

void    dfs(int **maps, int line, int n, int **condition)
{
    int i;

    if (line == n) 
    {
        if (check_final_condition(maps, n, condition) && g_find == 0)
        {
            print_map(maps, n);
            g_find = 1;
        }
        return ;
    }
    i = -1;
    while(++i < factorial_n && g_find == 0)
    {
        reset_line(maps[line], n);
        permutation(maps[line], i, n);
        if(check_line_condition(maps, line, n, condition))
            dfs(maps, line + 1, n, condition);
    }
}
void    rush(int **condition, int n)
{
    int **maps;
    int i;

    g_find = 0;
    factorial_n = factorial(n);
    if (check_initial_condition(condition, n) == 0)
    {   
        printError;
        return ;
    }
    maps = intialize_map(n);
    if(!maps)
    {
        printError;
        return ;
    }
    i = -1;
    while(++i < factorial_n && g_find == 0)
    {
        reset_line(maps[0], n);
        permutation(maps[0], i, n);
        if(check_line_condition(maps, 0, n, condition))
            dfs(maps, 1, n, condition);
    }
    freemaps(maps, n);
}

int main()
{
    int i;
    int **condition;
    condition = (int **)malloc(sizeof(int *) * 4);
    condition[0] = (int *)malloc(sizeof(int) * 10);
    condition[1] = (int *)malloc(sizeof(int) * 10);
    condition[2] = (int *)malloc(sizeof(int) * 10);
    condition[3] = (int *)malloc(sizeof(int) * 10);

    condition[0][0] = 10;
    condition[0][1] = 9;
    condition[0][2] = 8;    
    condition[0][3] = 7;    
    condition[0][4] = 6;   
    condition[0][5] = 5;  
    condition[0][6] = 4;
    condition[0][7] = 3;
    condition[0][8] = 2;
    condition[0][9] = 1;

    condition[1][0] = 1;
    condition[1][1] = 2;
    condition[1][2] = 2;    
    condition[1][3] = 2;       
    condition[1][4] = 2;       
    condition[1][5] = 2;       
    condition[1][6] = 2;       
    condition[1][7] = 2;       
    condition[1][8] = 2;       
    condition[1][9] = 2;       

    condition[2][0] = 10;
    condition[2][1] = 9;
    condition[2][2] = 8;    
    condition[2][3] = 7; 
    condition[2][4] = 6; 
    condition[2][5] = 5; 
    condition[2][6] = 4; 
    condition[2][7] = 3; 
    condition[2][8] = 2; 
    condition[2][9] = 1; 

    condition[3][0] = 1;
    condition[3][1] = 2;
    condition[3][2] = 2;    
    condition[3][3] = 2;     
    condition[3][4] = 2;     
    condition[3][5] = 2;     
    condition[3][6] = 2;     
    condition[3][7] = 2;     
    condition[3][8] = 2;     
    condition[3][9] = 2;     

    rush(condition, 10);
    
    i = -1;
    while(++i < 4)
        free(condition[i]);
    free(condition);
    return 0;
}
