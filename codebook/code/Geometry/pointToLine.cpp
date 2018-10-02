double cal(const pii &a,const pii &b,const pii &c){
	int hi=dot(mp(a.x-b.x,a.y-b.y),mp(c.x-b.x,c.y-b.y));
	if(hi<=0){
		return dis(a,b);
	} 
	hi=dot(mp(a.x-c.x,a.y-c.y),mp(b.x-c.x,b.y-c.y));
	if(hi<=0){
		return dis(c,a);
	}	
	if(b.x==c.x)
	return abs(a.x-b.x);
	if(b.y==c.y)
	return abs(a.y-b.y);
	double B=(double)(b.x-c.x)/(b.y-c.y);
	double C=(double)(b.y*c.x-b.x*c.y)/(b.y-c.y);
	return abs(-a.x+B*a.y+C)/sqrt(1+sqr(B));
}
