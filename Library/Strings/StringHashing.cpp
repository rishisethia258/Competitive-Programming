const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll base = 31;
vll pw(N);
vll inv(N);
vll hashVal(N);

ll add(ll a, ll b, ll mod) {
	ll res = (a + b) % mod;
	if(res < 0) 
		res += mod;
	return res;
}

ll mult(ll a, ll b, ll mod) {
	ll res = (a * b) % mod;
	if(res < 0) 
		res += mod;
	return res;
}

ll power(ll a, ll b, ll mod) {
	ll res = 1;
	while(b) {
		if(b & 1) 
			res = mult(res, a ,mod);
		a = mult(a, a, mod);
		b /= 2;
	}
	return res;
}

void precalc() {
	pw[0] = 1;
	fr(i,0,N)
		pw[i] = mult(pw[i - 1], base, mod);

	ll pw_inv = power(base, mod - 2, mod);
	inv[0] = 1;
	fr(i,0,N) 
		inv[i] = mult(inv[i - 1], pw_inv, mod);
}

void build(string s) {
	ll n = s.size();
	fr(i,0,n) {
		hashVal[i] = add((i == 0) ? 0 : hashVal[i - 1], mult(pw[i], s[i] - 'a' + 1, mod), mod);
	}
}

ll getHash(ll x, ll y) {
	ll res = add(hashVal[y], (x == 0) ? 0 : -hashVal[x - 1], mod);
	res = mult(res, inv[x], mod);
	return res;
}