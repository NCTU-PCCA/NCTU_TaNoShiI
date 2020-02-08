LL count_lattices(Fraction k, Fraction b, LL n) {
    // number of points(x,y) 0<=x<n,0<y<=k*x+b
    LL fk = floor(k);
    LL fb = floor(b);
    LL cnt = 0;
    if (fk >= 1 || fb >= 1) {
        cnt += (fk * (n - 1) + 2 * fb) * n / 2;
        k -= fk;b -= fb;
    }
    double t = k * n + b;
    LL ft = floor(t);
    if (ft >= 1) {
        cnt += count_lattices(1 / k, (t - ft) / k, ft);
    }
    return cnt;
}