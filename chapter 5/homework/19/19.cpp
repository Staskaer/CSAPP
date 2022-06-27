void faster_psum1a(float a[], float p[], long n)
{
    long i;
    float val = 0;
    for (i = 0; (i + 2) < n; i += 3)
    {
        float tmp1 = a[i];
        float tmp2 = tmp1 + a[i + 1];
        float tmp3 = tmp2 + a[i + 2];

        p[i] = val + tmp1;
        p[i + 1] = val + tmp2;
        p[i + 2] = val = val + tmp3;
    }
    for (; i < n; ++i)
    {
        val += a[i];
        p[i] = val;
    }
}