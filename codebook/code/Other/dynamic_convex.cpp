struct dynamic_convex{
    static int op;
    struct Line{
        LL a,b;
        LL x; 
        bool operator<(const Line &q) const{
            if(op == 0)return a < q.a;
            else return x < q.x;
        }
    };
    set<Line> s;
    void add_Line(Line l){
        op = 0;
        auto it = s.lower_bound(l);
        if(it != s.end() && it->a == l.a && it->b >= l.b)return;
        else{
            if(it != s.end() && it->a == l.a && it->b < l.b)
                s.erase(it);
            it = s.lower_bound(l);
            if(it != s.begin() && it != s.end()){
                auto it2 = prev(it);
                LL x = (it2->b - l.b) / (l.a - it2->a), x2 = (l.b - it->b) / (it->a - l.a);
                if(it2->b >= l.b)x++;
                if(l.b >= it->b)x2++;
                if(x >= x2)return;
            }
            while(it!=s.end()){
            //   printf("!\n");
                Line l1 = *it;
                it = next(it);
                s.erase(l1);
                int x = (l.b-l1.b) / (l1.a-l.a);
                if(l.b > l1.b)x++;
                if(it != s.end() && it->x <= x)continue;
                else{
                    l1.x = x;
                    s.insert(l1);
                    break;
                }
            }
            it = s.lower_bound(l);
            LL x=-1e9-7;
            while(it != s.begin()){
                //printf("!\n");
                auto it2 = prev(it);
                x = (it2->b - l.b) / (l.a - it2->a);
                if(it2->b >= l.b)x++;
                if(it2->x >= x){
                    s.erase(it2);
                    x = -1e9-7;
                }
                else{
                    break;
                }
            }
            l.x = x;
        //   printf("%d\n",x);
            s.insert(l);
        }
    }
    LL query(int p){
        if(s.empty())return -2e18;
        op = 1;
        Line l;
        l.x = p;
        auto it = prev(s.upper_bound(l));
        return it->a * p + it->b;
    }
};