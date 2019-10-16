LL solve(LL x1, LL m1, LL x2, LL m2){
    LL g = __gcd(m1, m2);
    if((x2 - x1) % g)return -1;
    m1 /= g; m2 /= g;
    pll p = gcd(m1, m2);
    LL lcm = m1 * m2 * g;
    LL res = p.x * (x2 - x1) * m1 + x1;
    return (res % lcm + lcm) % lcm;
}