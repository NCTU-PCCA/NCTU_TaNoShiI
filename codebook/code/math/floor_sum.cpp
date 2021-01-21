LL floor_sum(LL n, LL m, LL a, LL b) {
    //sum_0^{n-1}floor((a*i+b)/m)
    LL ans = 0;
    ans += (n - 1) * n * (a / m) / 2;
    a %= m;
    ans += n * (b / m);
    b %= m;
    LL y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}