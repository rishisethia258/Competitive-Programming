// Naive approach of Calculating nCr

ll nCr(ll n,ll r) { 
    ll p = 1, k = 1; 
    if (n - r < r) r = n - r; 
    if (r != 0) { 
        while (r) { 
         p *= n; k *= r; 
            ll m = __gcd(p, k); 
            p /= m; k /= m; n--; r--; 
        } 
   } 
    else p = 1; 
    return p; 
}

/* =========== FERMATS' LITTLE THEOREM ==================
   Let P be a prime number, and A be any integer. 
   Then (A^P) - A is always divisible by P. 
   In modular arithmetic notation, this can be written as
   (A^P) ≡ A mod P
   ======================================================*/

// Approach of Calculating nCr mod p

ll modpow(ll a, ll b,ll x) 
{
    ll res = 1; 
    while (b > 0) { 
        if (b & 1) res = (res * a)%x; 
        a = (a * a)%x; 
        b >>= 1;
    } 
    return res;
}

ll modInverse(ll n, ll p) { 
    return modpow(n, p - 2, p); 
}    

ll nCrModPFermat(ll n, ll r,ll p) { 
    if (r == 0) {
        return 1; 
    }
    ll fac[n + 1]; 
    fac[0] = 1; 
    for (ll i = 1; i <= n; i++) 
    {
        fac[i] = (fac[i - 1] * i) % p; 
    }
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 
