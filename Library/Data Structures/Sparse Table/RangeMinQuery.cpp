/*  =======================================
	Range Minimum Query using Sparse Table
	=======================================*/

// Precomputation - O(NlogN)
// Query - O(1)

const ll MAXN = 100005;
const ll K = (ll)log2(MAXN);
ll logarithm[MAXN];
ll st[MAXN][(K + 1ll)];

void build(vll array) {
    logarithm[1] = 0;
    for (ll i = 2; i <= MAXN; i++) {
        logarithm[i] = logarithm[i/2] + 1;
    }
    ll N = array.size();
    for (ll i = 0; i < N; i++) {
        st[i][0] = array[i];
    }
    for (ll j = 1; j <= K; j++) {
        for (ll i = 0; i + (1 << j) <= N; i++) {
            st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }    
}

ll query(ll L, ll R) {
    ll j = logarithm[(R - L + 1)];
    ll minimum = min(st[L][j],st[R-(1<<j)+1][j]);
    return minimum;
}