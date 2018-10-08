void FWT(int *x,int inv) {
    for(int i=1;i<lim;i<<=1){
        for(int j=0;j<lim;++j)/* or */
            if(j&i)
                x[j]= inv ? x[j]-x[j^i] : x[j]+x[j^i];
        for(int j=0;j<lim;j+=(i<<1))/* and */
            for(int k=0;k<i;++k)
                x[j+k]=inv ? x[j+k]-x[j+k+i] : x[j+k]+x[j+k+i];
        for(int j=0;j<lim;j+=(i<<1))/* xor */
            for(int k=0;k<i;++k) {
                int y=x[j+k],z=x[j+k+i];
                x[j+k]=inv ? (y+z)/2 : y+z;
                x[j+k+i]=inv ? (y-z)/2 : y-z;
            }
    }
}
 

