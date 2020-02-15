sort(p,p+n);
pii ans[N];
ans[0]=p[0];
int k=0,now=0;
for(int tt=0;tt<2;tt++){
	for(int i=1;i<n;i++){
		while(now!=k&&cross(ans[now],p[i],ans[now-1])<=0) now--;
		ans[++now]=p[i];
	}
	k=now;
	reverse(p,p+n);
}
