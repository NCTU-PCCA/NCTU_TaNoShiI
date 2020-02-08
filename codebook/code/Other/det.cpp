LL det(LL a[][20],int n) {  
    LL ret=1;  
    for(int i=1;i<n;i++){  
        for(int j=i+1;j<n;j++)  
            while(a[j][i]){  
                LL t=a[i][i]/a[j][i];  
                for(int k=i;k<n;k++)  
                    a[i][k]=a[i][k]-a[j][k]*t;  
                for(int k=i;k<n;k++)  
                    swap(a[i][k],a[j][k]);  
                ret=-ret;  
            }  
        if(a[i][i]==0)return 0;  
        ret=ret*a[i][i];  
    }  
    return ret;
}  