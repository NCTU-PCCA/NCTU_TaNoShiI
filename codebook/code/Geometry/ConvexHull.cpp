sort(p,p+n);
pii ans[N];
ans[0]=p[0];
int k=0;
int now=0;
for(int yy=0;yy<2;yy++){
	for(int i=1;i<n;i++){
		while(now!=k&&cross(ans[now].x,p[j].x,ans[now-1].x)<0){
			now--;
		} 
		ans[++now]=p[i];
	}
	k=now;
	reverse(p,p+n);
}
