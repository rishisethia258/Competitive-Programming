/*===================================================
   Range Sum Queries for 2D array using Fenwick Tree
  ===================================================*/

// Actions that can be performed ---
// * Calculate sum of rectangle from (0,0) to (x,y)
// * Update value of (x,y)

struct FenwickTree2D {
    vector<vector<ll>> bit;
    ll n, m;

    FenwickTree2D(ll n, ll m) {
        this->n = n;
        this->m = m;
        bit.assign(n, vll(m,0));
    }

    FenwickTree2D(vvll a) : FenwickTree2D(a.size(),a[0].size()) {
        for (size_t i = 0; i < a.size(); i++)
            for (size_t j = 0; j < a[0].size(); j++)
                add(i, j, a[i][j]);
    }

    ll sum(ll x, ll y) {
        ll ret = 0;
        for (ll i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (ll j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(ll x, ll y, ll delta) {
        for (ll i = x; i < n; i = i | (i + 1))
            for (ll j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};