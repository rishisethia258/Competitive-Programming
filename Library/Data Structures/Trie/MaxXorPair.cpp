// Author : rs258
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define RB rb_tree_tag
#define TSNU tree_order_statistics_node_update
template <typename T>
using oset = tree<T,null_type,less<T>,RB,TSNU>;
template <typename T>
using omultiset = tree<T,null_type,less_equal<T>,RB,TSNU>; 

#define ll         long long
#define ld         long double
#define endl       "\n"
#define pb         push_back
#define vll        vector<ll>
#define vvll       vector<vll>
#define pll        pair<ll,ll>
#define vbool      vector<bool>
#define vpair      vector<pll>
#define fi         first
#define se         second
#define mp(x,y)    make_pair(x,y)
#define all(a)     a.begin(),a.end()
#define rall(a)    a.rbegin(),a.rend()
#define mx(a)      *max_element(all(a))
#define mn(a)      *min_element(all(a))
#define rev(a)     reverse(all(a))
#define unq(a)     a.erase(std::unique(all(a)),a.end());
#define fr(i,a,b)  for(ll i=a;i<b;i++)
#define rf(i,a,b)  for(ll i=a;i>=b;i--)
#define yes()      cout<<"YES"<<endl
#define no()       cout<<"NO"<<endl
#define err()      cout<<"===========\n";
#define errA(A)    for(auto i:A) cout<<i<<" ";cout<<"\n";
#define err1(a)    cout<<#a<<" "<<a<<"\n"
#define err2(a,b)  cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"

const ll mod1 =    1000000007;
const ll mod2 =    998244353;
const ll infi =    1e18;

class Trie {
	private :
		class Node {
			Node* zero;
			Node* one;
			friend class Trie;
		};

		Node* root;

		void insert(Node* node, ll n) {
			Node* curr = node;
			rf(i,59,0) {
				ll bit = (n >> i) & 1;
				if(bit == 0) {
					if(curr -> zero == NULL) {
						curr -> zero = new Node();
					}
					curr = curr -> zero;
				} else {
					if(curr -> one == NULL) {
						curr -> one = new Node();
					}
					curr = curr -> one;
				}
			}
		}

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

		ll MaxXorPair(Node* node, vll a) {
			ll n = a.size();
			ll ans = 0;
			fr(i,0,n) {
				ll e = a[i];
				ll c = 0;
				Node* curr = node;
				rf(i,59,0) {
					ll bit = (e >> i) & 1;
					if(bit == 0) {
						if(curr -> one == NULL) {
							curr = curr -> zero;
						} else {
							curr = curr -> one;
							c += binpow(2,i);
						}
						
					} else {
						if(curr -> zero == NULL) {
							curr = curr -> one;
						} else {
							curr = curr -> zero;
							c += binpow(2,i);
						}
					}
				}
				ans = max(ans, c);
			}
			return ans;
		}

	public :
		Trie() {
			this -> root = new Node();
		}
		void insert(ll n) {
			insert(this -> root, n);
		}
		ll MaxXorPair(vll a) {
			return MaxXorPair(this -> root, a);
		}

};

void solve() {
	ll n; cin >> n;
	vll a(n);
	Trie* t = new Trie();
	fr(i,0,n) {
		cin >> a[i];
		t -> insert(a[i]);
	}
	cout << t -> MaxXorPair(a) << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1; 
    while(t--) solve();
    return 0;
}