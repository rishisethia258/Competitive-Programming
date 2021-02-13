/* ================================================ 
		Range Min Queries using Segment Tree
   ================================================*/

// Precomputation - O(N)
// Query - O(logN)

// While calling any functions default values must be -
// v = 1 
// tl = 0
// tr = n-1

const ll MAXN = 1e4 + 5;
ll n, t[4*MAXN];

void build(vll a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

ll getMin(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return infi;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return min(getMin(v*2, tl, tm, l, min(r, tm))
           , getMin(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}