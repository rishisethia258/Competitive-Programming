ll maxSubarraySum(vll a) {
	ll n = a.size();
	ll b = 0, s = 0;
	fr(k,0,n) {
		s = max(a[k],s+a[k]);
		b = max(b,s);
	}
	return b;
}