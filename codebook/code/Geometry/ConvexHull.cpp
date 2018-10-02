sort(p,p+n);
pii ans[N];
ans[0]=p[0];
int k=0;
int now=0;
for(int yy=0;yy<2;yy++){
	for(int i=1;i<n;i++){
		while(now!=k&&(p[i].y-ans[now-1].y)*(ans[now].x-ans[now-1].x)<=(p[i].x-ans[now-1].x)*(ans[now].y-ans[now-1].y)){
			now--;
		} 
		ans[++now]=p[i];
	}
	k=now;
	reverse(p,p+n);
}
