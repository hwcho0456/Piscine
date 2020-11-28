#include <stdlib.h>

int     factorial(int n)
{
    if (n < 0)
        return (0);
    else if ( n == 0)
        return (1);
    else
        return (n * factorial(n - 1));
}

void    swap(int *arr, int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int    **make_line(int n)
{
    int normal
    int **arrays;
    int count;
    int i;
    int j;
    int k;

    normal = 1;
    count = factorial(n);
    arrays = (int **)malloc(sizeof(int *) * count);
    if(!arrays)
        return NULL;
    i = -1;
    while(++i < count)
    {
        arrays[i] = (int *)malloc(sizeof(int) * n);
        if(!arrays[i])
        {
            normal = 0;
            break;
        }
        j = -1;
        while(++j < n)
            arrays[i][j] = j + 1;
        while(j > 1)
        {
            k = i % j;
            swap(arrays[i], n - j, n - j + k); 
            j--;
        }
    }
    if (normal == 0)
    {
        while(i >= 0)
        {
            free(arrays[i]);
            i--;
        }
        free(arrays);
    }
    return arrays;
}
