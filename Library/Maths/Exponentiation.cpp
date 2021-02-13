ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) { 
    	if (b & 1) {
            res = (res * a);   
        }
    	a = (a * a);
    	b >>= 1;
    }
    return res;
}

ll modpow(ll a, ll b,ll x) 
{
    ll res = 1; 
    while (b > 0) { 
    	if (b & 1) {
            res = (res * a) % x;
        } 
    	a = (a * a)%x; 
    	b >>= 1;
    } 
    return res;
}

ll modInverse(ll n, ll p) { 
    return modpow(n, p - 2, p); 
}   