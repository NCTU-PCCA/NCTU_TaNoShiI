
const int mod=1e9+7,rev=(mod+1)>>1;
void FWT(int *a,int n,int inv)
{
    for(int d=1; d<n; d<<=1)
        for(int m=d<<1,i=0; i<n; i+=m)
            for(int j=0; j<d; j++)
            {
                int x=a[i+j],y=a[i+j+d];
				if(inv)
					a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
				else 
					a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod; 
            }
}W
 

