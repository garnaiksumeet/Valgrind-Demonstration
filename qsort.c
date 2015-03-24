/* This is program that just for the purpose of demonstration.
 * The quick_sort function has been used from rosettacode.org
 * The goal of this file is demonstration of timing and memory
 * profiling using valgrind.*/


#include<stdio.h>
#include<stdlib.h>

void quick_sort(int *a, int n);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int *a = (int *)malloc(sizeof(int)*n);
    int *b = (int *)malloc(sizeof(int)*n);
    int i;

    for (i=0;i<n;i++)
    {
	*(a+i) = rand();
	*(b+i) = rand();
    }
    quick_sort(a, n);
    free(a);
    quick_sort(b, n);
    free(b);
    return 0;
}

void quick_sort(int *a, int n)
{
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--)
    {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quick_sort(a, i);
    quick_sort(a + i, n - i);
}
