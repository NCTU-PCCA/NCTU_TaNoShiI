struct DLX{
    int n,m,len;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[maxn];
    int S[maxm];
    int ansd,ans[maxn];
 
    void init(int _n,int _m){
        n = _n;m = _m;
        for(int i = 0; i <= m; i++){
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0,L[0] = m;
        len = m;
        for(int i = 1; i <= n; i++)
            H[i] = -1;
    }
 
    void link(int r,int c){
        ++S[Col[++len]=c];
        Row[len] = r;
        D[len] = D[c];
        U[D[c]] = len;
        U[len] = c;
        D[c] = len;
        if(H[r] < 0)
            H[r] = L[len] = R[len] = len;
        else{
            R[len] = R[H[r]];
            L[R[H[r]]] = len;
            L[len] = H[r];
            R[H[r]] = len;
        }
    }
 
    void del(int c){
        L[R[c]] = L[c];
        R[L[c]] = R[c];
        for(int i = D[c]; i != c; i = D[i]){
            for(int j = R[i]; j != i; j = R[j]){
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
        }
    }
 
    void resume(int c){
        for(int i = U[c]; i != c; i = U[i]){
            for(int j = L[i]; j != i; j = L[j]){
                ++S[Col[U[D[j]]=D[U[j]]=j]];
            }
        }
        L[R[c]] = R[L[c]] = c;
    }
 
    void dance(int d){
        //剪枝
        if(ansd != -1 && ansd <= d)
            return;
        if(R[0] == 0){
            if(ansd == -1)
                ansd = d;
            else if(d < ansd)
                ansd = d;
            return ;
        }
        int c = R[0];
        for(int i = R[0]; i != 0; i = R[i]){
            if(S[i] < S[c])
                c = i;
        }
        del(c);
        for(int i = D[c]; i != c; i = D[i]){
            ans[d] = Row[i];
            for(int j = R[i]; j != i; j = R[j])
                del(Col[j]);
            dance(d+1);
            for(int j = L[i]; j != i; j = L[j])
                resume(Col[j]);
        }
        resume(c);
    }
};
