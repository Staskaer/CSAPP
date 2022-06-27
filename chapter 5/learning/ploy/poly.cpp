#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 为什么计算出来的时间都是0呢

double poly1(double a[], double x, long long degree)
{
    long long i;
    double result = a[0];
    double xpwr = x;
    for (i = 1; i <= degree; i++)
    {
        result += a[i] * xpwr;
        xpwr = x * xpwr;
    }
    return result;
}

double poly2(double a[], double x, long long degree)
{
    long long i;
    double result = a[degree];
    for (i = degree - 1; i >= 0; i--)
        result = a[i] + x * result;
    return result;
}

int main()
{

    double a[1000000000];
    for (long long i = 0; i < 1000000000; i++)
    {
        a[i] = 1;
    }

    clock_t start, finish;
    double total_time, res;
    printf("test poly1 : ");
    start = clock();
    res = poly1(a, 5, 1000000000 - 1);
    finish = clock();
    total_time = (double)(finish - start);
    printf(" times = %lf\n", total_time);

    printf("test poly2 : ");
    start = clock();
    res = poly2(a, 5, 1000000000 - 1);
    finish = clock();
    total_time = (double)(finish - start);
    printf(" times = %lf\n", total_time);

    system("pause");
}