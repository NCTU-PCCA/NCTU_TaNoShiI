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
\item Stirling Numbers(permutation $|P|=n$ with $k$ cycles): \\
  $S(n,k) = \text{coefficient of }x^k \text{ in } \Pi_{i=0}^{n-1} (x+i)$
\item Stirling Numbers(Partition $n$ elements into $k$ non-empty set): \\
  $S(n,k) = \frac{1}{k!} \sum\limits_{j=0}^k (-1)^{k-j} {k \choose j} j^n$
*/