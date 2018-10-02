inline void z_alg1(char *s,int len,int *z){
	int l=0,r=0;
	z[0]=len;
	for(int i=1;i<len;++i){
		z[i]=r>i?min(r-i+1,z[z[l]-(r-i+1)]):0;
		while(i+z[i]<len&&s[z[i]]==s[i+z[i]])++z[i];
		if(i+z[i]-1>r)r=i+z[i]-1,l=i;
	}
}
