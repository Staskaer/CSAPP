double poly(double a[], double x, long degree)
{
    //采用循环展开a的方法
    long i = 1;
    double result = a[0];
    double result1 = 0;
    double result2 = 0;
    double xpwr = x;
    double xpwr1 = x * x * x;
    double xpwr2 = x * x * x * x * x;
    double xpwr_loop = x * x * x * x * x * x;
    for (; i <= degree - 6; i += 6)
    {
        result = result + (a[i] * xpwr + a[i + 1] * xpwr * x);
        result1 = result1 + (a[i + 2] * xpwr1 + a[i + 3] * xpwr1 * x);
        result2 = result2 + (a[i + 4] * xpwr2 + a[i + 5] * xpwr2 * x);
        xpwr *= xpwr_loop;
        xpwr1 *= xpwr_loop;
        xpwr2 *= xpwr_loop;
    }

    for (; i <= degree; i++)
    {
        result = result + a[i] * xpwr;
        xpwr *= x;
    }
    return result + result1 + result2;
}