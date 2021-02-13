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
