
long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 60:
    case 62:
        result = 8 * x;
        break;

    case 63:
        result >>= 3;
        break;
    case 64:
        // result = x;
        result <<= 0x4;
        result -= x;

    case 65:
        result *= result;

    case 61:
    default:
        result += 0x4b;
    }
    return result;
}

//gcc -O3 -S 63.cpp