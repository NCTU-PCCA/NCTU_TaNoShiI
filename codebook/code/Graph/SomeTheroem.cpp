/*
General graph
|maximum independent set|+|minimum vertex cover|=|V|
|maximum independent edge|+|minimum edge cover|=|V|
      ||
Max_match
Bipartite graph
|Maximun independent set|=|Minimun edge cover| 
|Maximun independent edge|=|Minimun vertex cover|
|Maximun Independent set|+|Minimun vertex cover|=|V|
           +                    +
|Maximun Independent edge|+|Minimun edge cover|=|V|
          ||                      || 
         |V|                     |V|
DAG dilworth's theorem
Minimal chain cover = Maximal antichain
Maximal atichain = Minimal antichain cover
number of labeled forest n vertices with k tree
1,2,3,4...k belong different tree
kn^(n-k-1)
Erdős–Gallai theorem
d_1 \geq d_2 ... \geq d_n
\sum^k_{i=1} d_i \leq k(k-1) + \sum_{i=k+1}^n min(d_i,k)
*/