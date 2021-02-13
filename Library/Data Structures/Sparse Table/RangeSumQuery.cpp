/* =====================================
	Range Sum Query using Sparse Table 
   =====================================*/

// Precomputation - O(NlogN)
// Query - O(logN)

const ll MAXN = 100005;
const ll K = (ll)log2(MAXN);
ll st[MAXN][K + 1];

void build(vll array) {
    ll N = array.size();
    for (ll i = 0; i < N; i++) {
        st[i][0] = array[i];
    }
    for (ll j = 1; j <= K; j++) {
        for (ll i = 0; i + (1 << j) <= N; i++) {
            st[i][j] = st[i][j-1] + st[i+(1<<(j-1))][j-1];
        }
    }
}

ll query(ll L,ll R) {
    ll sum = 0;
    for (ll j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            sum += st[L][j];
            L += 1 << j;
        }
    }
    return sum;
}