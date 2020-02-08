pair<pll,pll> fraction_b(int n,int m){
    pll Max=mp(1,0),Min=mp(0,1);
    int Big=0;
    while(true){
        if(Max.x+Min.x>n||Max.y+Min.y>m)break;
        if(Big){
            LL large;
            for(large = 1;;large<<=1){
                pll p=mp(Max.x*large+Min.x,Max.y*large+Min.y);
                if(cal(p,n,m)>=x)break;
                if(p.x>n||p.y>m){
                    large>>=1;
                    break;
                }
            }
            int add=0;
            for(;large;large>>=1){
                pll p=mp(Max.x*(add+large)+Min.x,Max.y*(add+large)+Min.y);
                if(cal(p,n,m)<x&&p.x<=n&&p.y<=m)add+=large;
            }
            Min=mp(Max.x*add+Min.x,Max.y*add+Min.y);
            if(Max.x+Min.x<=n&&Max.y+Min.y<=m)
            Max=mp(Max.x+Min.x,Max.y+Min.y);
        }
        else{
            int large;
            for(large = 1;;large<<=1){
                pll p = mp(Max.x+Min.x*large,Max.y+Min.y*large);
                if(cal(p,n,m)<x)break;
                    if(p.x>n||p.y>m){
                    large>>=1;
                    break;
                }
            }
            int add=0;
            for(;large;large>>=1){
                pll p =mp(Min.x*(add+large)+Max.x,Min.y*(add+large)+Max.y);
                if(cal(p,n,m)>=x&&p.x<=n&&p.y<=m)add+=large;
                
            }
            Max=mp(Min.x*add+Max.x,Min.y*add+Max.y);
            if(Max.x+Min.x<=n&&Max.y+Min.y<=m)
            Min=mp(Max.x+Min.x,Max.y+Min.y);
        }
        Big^=1;
    }
    return mp(Min,Max);
}