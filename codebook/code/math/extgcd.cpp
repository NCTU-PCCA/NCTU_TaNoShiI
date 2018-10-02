typedef pair<int, int> pii;
pii gcd(int a, int b){
    if(b == 0) return mp(1, 0);
    else{
        int p = a / b;
        pii q = gcd(b, a % b);
        return make_pair(q.y, q.x - q.y * p);
    }
}
