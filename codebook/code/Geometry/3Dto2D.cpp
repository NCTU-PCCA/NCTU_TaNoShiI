Point randomver(Point a){
	if(abs(a.x)<1e-6)return {1,0,0};
	if(abs(a.y)<1e-6)return {0,1,0};
	if(abs(a.z)<1e-6)return {0,0,1};
	Point ret = Point(a.y*a.z,a.x*a.z,-2*a.x*a.y);
	ret = ret * (1/ret.len());
	return ret;
}
vector<pdd> to2D(vector<Point> v,Point vec, Point p){
	for(auto &it:v){
		it = it-p;
	}
	//cout<<vec.x<<" "<<vec.y<<" "<<vec.z<<endl;
	Point r = randomver(vec);
	Point c = cross(vec,r);
	vector<pdd> ret;
	for(auto it:v){
		ld x = it*r/r.len();
		ld y = it*c/c.len();
		ret.pb(mp(x,y));
	//	cout<<x<<" "<<y<<" "<<it*r<<" "<<r.len()<<endl;
	}
	return ret;
}