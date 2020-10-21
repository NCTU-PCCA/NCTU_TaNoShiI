bool cmp(const pll &p,const pll &q){
  int a=(p.x<0||(p.x==0&&p.y<0));
  int b=(q.x<0||(q.x==0&&q.y<0));
  if(a!=b)return a<b;
  return (p^q)>0;
}
vector<pll> minkowski(vector<pll> p, vector<pll> q){
  int n = p.size() , m = q.size();
  pll st=p[0]+q[0];
  vector<pll> v1,v2,v(n + m);
  for(int i = 0;i<n;i++) v1.pb(p[(i+1)%n]-p[i]);
  for(int i = 0;i<m;i++) v2.pb(q[(i+1)%m]-q[i]);
  merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin(),cmp);
  vector<pll> h{st};
  pll last=mp(0,0);
  int fi=1;
  for(auto it:v){
    st=st+it;
    if(!fi&&!cmp(last,it)&&!cmp(it,last))
      h.pop_back();
    last=it;
    fi=0;
    h.pb(st);
  }
  h.pop_back();
  return h;
}