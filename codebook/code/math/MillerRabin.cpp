// 4759123141	2, 7, 61
//2^64 2, 325, 9375, 28178, 450775, 9780504, 1795265022	
bool Isprime(LL n)
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    LL u = n - 1, t = 0;
    while (u % 2 == 0) {u >>= 1; t++;}
    LL sprp[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (int k=0; k<7; ++k)
    {
        LL a = sprp[k] % n;
        if (a == 0 || a == 1 || a == n-1) continue;
        long long x = f_pow(a, u, n);
        if (x == 1 || x == n-1) continue;
        for (int i = 0; i < t-1; i++)
        {
            x = f_pow(x, 2, n);
            if (x == 1) return false;
            if (x == n-1) break;
        }
        if (x == n-1) continue;
        return false;
    }
    return true;
}
