// Function to factorize numbers using sieve

const ll N = 1e4 + 5;
ll spf[N];

void sieve() { 
    spf[1] = 1;
    for (ll i = 2; i < N ; i++) {
    	spf[i] = i; 
    }	
    for (ll i = 4; i < N ; i += 2) {
    	spf[i] = 2; 
    } 
    for (ll i = 3; (i*i) < N ; i++) {
    	if (spf[i] == i) {
    		for (ll j=i*i; j<N; j+=i) {
    			if (spf[j]==j) {
    				spf[j] = i; 
    			}
    		}
    	}
    }	
} 

vector<ll> getFactorization(ll x) {
    vector<ll> ret;
    while (x != 1) { 
    	ret.push_back(spf[x]); 
    	x = x / spf[x]; 
    }
    return ret;
}