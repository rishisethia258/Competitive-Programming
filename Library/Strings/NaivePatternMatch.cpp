// Time Complexity - O(n * m)

vll search(string text, string pat) {
	vll in;
	ll n = text.size();
	ll m = pat.size();
	fr(i,0,n-m+1) {
		bool ok = true;
		fr(j,0,m) {
			if(pat[j] != text[i+j]) {
				ok = false;
				break;
			}
		}
		if(ok) {
			in.pb(i);
		}
	}
	return in;
}