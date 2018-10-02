#define N 524288
#define pi acos(-1)
typedef complex<double> C;
int n,m,i,t,g[N];
C a[N],b[N];
void FFTinit(){
	for (i=1;i<N;i++) g[i]=g[i>>1]>>1|((i&1)<<18);
}
void FFT(C *a,int f)
{
	int i,j,k,p;
	for (i=0;i<N;i++)
		if (g[i]>i) swap(a[i],a[g[i]]);
	for (i=1;i<N;i<<=1)
	{
		C e(cos(pi/i),f*sin(pi/i));
		for (j=0;j<N;j+=i<<1)
		{
			C w(1,0);for (k=0;k<i;k++,w*=e)
			{
				C x=a[j+k],y=w*a[j+k+i];
				a[j+k]=x+y;a[j+k+i]=x-y;
			}
		}
	}
}
int res[400005];
int main()
{
	FFTinit();
	FFT(a,1);
	FFT(b,1);
	for(i=0;i<N;i++) a[i]=a[i]*b[i]; 
	FFT(a,-1);
	for (i=0;i<n+m;i++)
	(int)a[i].real()/N+0.5)
}
