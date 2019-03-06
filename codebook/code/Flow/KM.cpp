struct KM{
    // Maximum Bipartite Weighted Matching (Perfect Match)
    static const int MXN = 650;
    const int INF = 2147483647; //LL
    int px[MAXN],py[MAXN],match[MAXN],par[MAXN],n;
    int g[MAXN][MAXN],lx[MAXN],ly[MAXN],slack_y[MAXN];
    // ^^^^ long long
    void init(int _n){
        n = _n;
        for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        g[i][j] = 0;
    }
    void add_edge(int x, int y, int w){ // LL
        g[x][y] = w;
    }
    void adjust(int y){
        match[y]=py[y];
        if(px[match[y]]!=-2)
            adjust(px[match[y]]);
    }
    bool dfs(int x){
        for(int y=0;y<n;++y){
            if(py[y]!=-1)continue;
            int t=lx[x]+ly[y]-g[x][y];//LL
            if(t==0){
                py[y]=x;
                if(match[y]==-1){
                    adjust(y);
                    return 1;
                }
                if(px[match[y]]!=-1)continue;
                px[match[y]]=y;
                if(dfs(match[y]))return 1;
            }else if(slack_y[y]>t){ 
                slack_y[y]=t;
                par[y]=x;
            }
        }
        return 0;
    }
    int solve(){//LL
        fill(match,match+n,-1);
        fill(ly,ly+n,0);
        for(int i=0;i<n;++i){
            lx[i]=-INF;
            for(int y=0;y<n;++y){
                lx[i]=max(lx[i],g[i][y]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)slack_y[j]=INF;
            fill(px,px+n,-1);
            fill(py,py+n,-1);
            px[i]=-2;
            if(dfs(i))continue;
            bool flag=1;
            while(flag){
                int cut=INF; //LL
                for(int j=0;j<n;++j)
                    if(py[j]==-1)cut=min(cut,slack_y[j]);
                for(int j=0;j<n;++j){
                    if(px[j]!=-1)lx[j]-=cut;
                    if(py[j]!=-1)ly[j]+=cut;
                    else slack_y[j]-=cut;
                }
                for(int y=0;y<n;++y){
                    if(py[y]==-1&&slack_y[y]==0){
                        py[y]=par[y];
                        if(match[y]==-1){
                            adjust(y);
                            flag=0;
                            break;
                        }
                        px[match[y]]=y;
                        if(dfs(match[y])){
                            flag=0;
                            break;
                        }
                    }
                }
            }
        }
        int res=0;//LL
        for(int i=0;i<n;++i)
            res+=g[match[i]][i];
        return res;
    }
}graph;