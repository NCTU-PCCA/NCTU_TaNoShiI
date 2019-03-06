list<int> mylist;
vector<list<int>::iterator> v;
vector<int> vis;
int search(list<int>::iterator x,int i,int n){
    int Max=n+1,Min=*x;
    list<int>::iterator last=x;
    last--;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int a=*last,b=*x;
        int val1=dp[a][i-1]+cost[a+1][mid],val2=dp[b][i-1]+cost[b+1][mid];
        if(val1>=val2)Max=mid;
        else Min=mid;
    }
    return Max;
}
priority_queue<pii,vector<pii>,greater<pii> > pq;
for(int i=2;i<=m;i++){
    mylist.clear();mylist.pb(i-1);
    v.clear();v.resize(n);
    vis.clear();vis.resize(n+1,0);
    for(int j=i;j<=n;j++){
        while(!pq.empty()&&pq.top().x<=j){
            pii p=pq.top();pq.pop();
            if(vis[p.y])continue;
            auto it=v[p.y];it--;
            vis[*it]=1;mylist.erase(it);
            if(v[p.y]!=mylist.begin())
                pq.push(mp(search(v[p.y],i,n),p.y));
        }
        int opt=mylist.front();
        dp[j][i]=dp[opt][i-1]+cost[opt+1][j];
        mylist.push_back(j);
        v[j]=mylist.end();v[j]--;
        pq.push(mp(search(v[j],i,n),j));
    }
    while(!pq.empty())pq.pop();
}