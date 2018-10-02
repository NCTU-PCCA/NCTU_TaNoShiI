vector<vector<int> > v;
int vis[100005],lwn[100005];
vector<int> stk;
int f[100005];
int bln[100005];
int Find(int a){
	if(bln[a]==a)return a;
	return bln[a]=Find(bln[a]);
}
int t;
void dfs(int a,int p){
	stk.pb(a);
	bln[a]=a;
	vis[a]=lwn[a]=++t;
	int cnt=0;
	for(int i=0;i<v[a].size();i++){
		int x=v[a][i];
		if(x!=p||cnt==1){
			if(vis[x]==0){
				dfs(x,a);
				if(lwn[x]>vis[a]){
					int fa=Find(x);
					f[x]=Find(a);
					while(stk.back()!=x){
						bln[stk.back()]=fa;
						stk.pop_back();
					}
					bln[stk.back()]=fa;
					stk.pop_back();
				}
				lwn[a]=min(lwn[a],lwn[x]);
			}
			else{
				lwn[a]=min(lwn[a],vis[x]);
			}
		}
		else{
			cnt++;
		}
	}
}
