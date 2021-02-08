/*
Lucas's Theorem:
For non-negative integer n,m and prime P,
C(m,n) mod P = C(m/P,n/P) * C(m%P,n%P) mod P
-------------------------------------------------------
Pick's Theorem
A = i + b/2 - 1
-------------------------------------------------------
Erdős–Gallai theorem
\sum_{i=1}^k d_i \leq k*(k-1)+\sum_{i=k+1}^n min(d_i,k)
d_i decrease
-------------------------------------------------------
meissel-lehmer
p_1=2
pi(n) = phi(n,m) - P2(n,m) + m - 1 p_m>=n^1/3, pi=prime count
P2(n,m) = \sum_{p_m\lt p \le sqrt(n)}(pi(n/p) - pi(p) + 1)
P2(n,m) = number of x whose has 2 prime factor and greater than p_m
phi(n,m) = phi(n,m-1) - phi(n/p_m,m-1)
phi(n,0) = n
if(n<p_m)phi(n,m)=1
phi = number of x whose prime factor greater than p_m
10^11 4118054813
\item Stirling Numbers(permutation $|P|=n$ with $k$ cycles): \\
  $S(n,k) = \text{coefficient of }x^k \text{ in } \Pi_{i=0}^{n-1} (x+i)$
\item Stirling Numbers(Partition $n$ elements into $k$ non-empty set): \\
  $S(n,k) = \frac{1}{k!} \sum\limits_{j=0}^k (-1)^{k-j} {k \choose j} j^n$
\item Stirling approximation
  $n!=\sqrt{2\pi n}(\frac{n}{e})^n(1+\frac{1}{12n}+\frac{1}{288n^2}-\frac{139}{51840n^3})$
*/