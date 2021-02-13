// This function returns Longest Increasing Subsequence 

vll lis(vll a) {
    ll n = a.size(),index = 0;
    vll d(n+1,1e18),in(n+1,-1),p(n,-1),subseq;
    d[0] = -1e18;
    fr(i,0,n) {
        ll j = ub(d,a[i]) - d.begin();
        if(a[i] > d[j-1] && a[i] < d[j]) {
            d[j] = a[i];
            in[j] = i;
            p[i] = in[j-1];
        }
    }
    fr(i,0,n+1) {
        if(d[i] < 1e18)
            index = in[i];
    }
    while(index != -1) {
        subseq.pb(a[index]);
        index = p[index];
    }
    rev(subseq);
    return subseq;
}