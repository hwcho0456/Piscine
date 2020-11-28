#include <stdio.h>

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
void    swap(int *arr, int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void    *permutation(int *line_map, int i, int n)
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

void    *reset(int *line_map, int n)
{
    int i= -1;
    while(++i < n)
    {
        line_map[i] = i+1;
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    int i=0;
    while(i < factorial(5))
    {
        reset(a, 5);
        permutation(a, i, 5);
        for(int j=0; j <5; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
        i++;
    }
    return 0;
}


