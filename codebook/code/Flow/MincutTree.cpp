set<int> temp;
int Vis[3005];
int cvis[3005];
void dfs(int n){
	Vis[n]=1;
	for(auto it=v[n].begin();it!=v[n].end();it++){
		if(val[n][*it]>flow[n][*it]&&!Vis[*it]){
			dfs(*it);
			if(cvis[*it])
			temp.insert(*it);
		}
	}
}
int n;
int dc(set<int> s,int flag){
	if(s.size()==1)
	return *s.begin();
	for(int i=0;i<n;i++)
		for(auto it=v[i].begin();it!=v[i].end();it++)
		flow[i][*it]=0;
	for(auto it=s.begin();it!=s.end();it++){
		cvis[*it]=1;
	}
	int res=Flow(*s.begin(),*s.rbegin());
	MEM(Vis);
	dfs(*s.begin());
	temp.insert(*s.begin());
	for(auto it=s.begin();it!=s.end();it++){
		cvis[*it]=0;
	} 
	set<int> s1,s2;
	swap(s1,temp);
	temp.clear();
	for(auto it=s1.begin();it!=s1.end();it++)
	s.erase(*it);
	swap(s2,s);
	int x=dc(s1,0);
	int y=dc(s2,1);
	vt[x].pb(mp(y,res));
	vt[y].pb(mp(x,res));
	if(flag==0)
	return x;
	else
	return y;
}
