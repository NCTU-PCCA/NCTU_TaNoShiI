ll a[10],n[10],k,k2;
int cs;
vector<PLL> v[100];
int srt(PLL a,PLL b){
    return a.Y>b.Y;
}
PLL extgcd(ll a,ll b){
    if(b==0) return mp(1,0);
    ll p;
    PLL q;
    p = a/b;
    q = extgcd(b,a%b);
    return mp(q.Y,q.X-q.Y*p);
}
ll crt (){
    ll i,alln,mf,ans,mi,ci;
    PII f;
    alln = 1;
    ans = 0;
    for(i=0;i<k;i++) alln *= n[i];
    for(i=0;i<k;i++){
        mi = alln/n[i];
        mf = extgcd(mi,n[i]).X; // m[i]*mf % n[i] = 1
        ci = mi*(mf % n[i]); // m[i] * (mf % n[i])
        ans= ( (ans + (a[i]*ci))%alln + alln)%alln;
    }
    return (ans==0?alln:ans);
}
int chg(){
    ll f,mi,xa,xm,c;
    REP(i,k){
        f = n[i];
        REP1(j,2,f+1){
            c = 0;
            mi = 1;
            while(f%j == 0){
                f/=j;
                c++;
                mi*=j;
            }
            if(c)v[j].pb(mp(a[i]%mi,mi));
        }
    }
    k = 0;
    REP(i,100){
        if(LE(v[i])){
            sort(ALL(v[i]),srt);
            REP(j,LE(v[i])){
                xa = v[i][j].X;
                xm = v[i][j].Y;
                if(v[i][0].X % xm != xa % xm)
                    return 0;
            }
            a[k] = v[i][0].X;
            n[k] = v[i][0].Y;
            k++;
        }
    }
    return 1;
}