#define N
void init();//implement
int n,fa[N],belong[N],dep[N],sz[N],que[N];
int step,line[N],stPt[N],edPt[N];
vector<int> v[N], chain[N];
void DFS(int u){
    vector<int> &c = chain[belong[u]];
    for (int i=c.size()-1; i>=0; i--){
        int v = c[i];
        stPt[v] = step;
        line[step++] = v;
    }
    for (int i=0; i<(int)c.size(); i++){
        u = c[i];
        for (vector<int>::iterator it=v[u].begin();it!=v[u].end();it++){
            if (fa[u] == *it || (i && *it == c[i-1])) continue;
            DFS(*it);
        }
        edPt[u] = step-1;
    }
}
void build_chain(int st){
    int fr,bk;
    fr=bk=0; que[bk++] = 1; fa[st]=st; dep[st]=0;
    while (fr < bk){
        int u=que[fr++];
        for (vector<int>::iterator it=v[u].begin();it!=v[u].end();it++){
            if (*it == fa[u]) continue;
            que[bk++] = *it;
            dep[*it] = dep[u]+1;
            fa[*it] = u;
        }
    }
    for (int i=bk-1,u,pos; i>=0; i--){
        u = que[i]; sz[u] = 1; pos = -1;
        for (vector<int>::iterator it=v[u].begin();it!=v[u].end();it++){
            if (*it == fa[u]) continue;
            sz[u] += sz[*it];
            if (pos==-1 || sz[*it]>sz[pos]) pos=*it;
        }
        if (pos == -1) belong[u] = u;
        else belong[u] = belong[pos];
        chain[belong[u]].pb(u);
    }
    step = 0;
    DFS(st);
}
int getLCA(int u, int v){
    while (belong[u] != belong[v]){
        int a = chain[belong[u]].back();
        int b = chain[belong[v]].back();
        if (dep[a] > dep[b]) u = fa[a];
        else v = fa[b];
    }
    return sz[u] >= sz[v] ? u : v;
}
vector<pii> getPathSeg(int u, int v){
    vector<pii> ret1,ret2;
    while (belong[u] != belong[v]){
        int a = chain[belong[u]].back();
        int b = chain[belong[v]].back();
        if (dep[a] > dep[b]){
            ret1.pb(mp(stPt[a],stPt[u]));
            u = fa[a];
            } else {
            ret2.pb(mp(stPt[b],stPt[v]));
            v = fa[b];
        }
    }
    if (dep[u] > dep[v]) swap(u,v);
    ret1.pb(mp(stPt[u],stPt[v]));
    reverse(ret2.begin(), ret2.end());
    ret1.insert(ret1.end(),ret2.begin(),ret2.end());
    return ret1;
}
// Usage
void build(){
    build_chain(1); //change root
    init();
}
int get_answer(int u, int v){
    int ret = -2147483647;
    vector<pii> vec = getPathSeg(u,v);
    for (vector<pii>::iterator it =vec.begin();it!= vec.end();it++);
     // check answer with segment [it.F, it.S]
    return ret;
}
