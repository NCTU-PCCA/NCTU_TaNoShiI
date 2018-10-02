int ss[N];
int heigh[N];
int sa[N];
int rank[N];
int length;
int val[30];
int c[N];   // counting sort array
int temp[2][N];
void suffix_array()
{
    int A = 250;          
    int* rank = temp[0];
    int* new_rank = temp[1];
    for (int i=0; i<A; ++i) c[i] = 0;
    for (int i=0; i<length; ++i) c[rank[i] = ss[i]]++;
    for (int i=1; i<A; ++i) c[i] += c[i-1];
    for (int i=length-1; i>=0; --i) sa[--c[ss[i]]] = i;
    for (int n=1; n<length; n*=2)
    {
        for (int i=0; i<A; ++i) c[i] = 0;
        for (int i=0; i<length; ++i) c[rank[i]]++;
        for (int i=1; i<A; ++i) c[i] += c[i-1];
        int* sa2 = new_rank;       
        int r = 0;                  
        for (int i=length-n; i<length; ++i)   
            sa2[r++] = i;           
        for (int i=0; i<length; ++i)    
            if (sa[i] >= n)       
                sa2[r++] = sa[i] - n;
        for (int i=length-1; i>=0; --i)
            sa[--c[rank[sa2[i]]]] = sa2[i];
        new_rank[sa[0]] = r = 0;
        for (int i=1; i<length; ++i)
        {
            if (!(rank[sa[i-1]] == rank[sa[i]] &&
                sa[i-1]+n < length &&    // stable sort trick
                rank[sa[i-1]+n] == rank[sa[i]+n]))
                r++;
            new_rank[sa[i]] = r;
        }
        swap(rank, new_rank);
        if (r == length-1) break;
        A = r + 1;
    }
}
void lcp_array()
{
    for (int i=0; i<length; ++i)
        rank[sa[i]] = i;
 
    for (int i=0, lcp=0,h=0; i<length; i++)
        if (rank[i] == 0)
            heigh[0] = 0;
        else
        {
            int j = sa[rank[i]-1];
            if (lcp > 0) lcp-=val[ss[i-1]-'a'],h--;
            while (ss[i+h] == ss[j+h]) lcp+=val[ss[i+h]-'a'],h++;
            heigh[rank[i]] = lcp;
        }
}
