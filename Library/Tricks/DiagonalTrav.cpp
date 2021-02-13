// Diagonal Traversal of n x m matrix

/* 
	| 1 2 3 |		
	| 4 5 6 | => 1 - 4 2 - 7 5 3 - 8 6 - 9 
	| 7 8 9 |
*/

fr(l,1,n+m) 
{ 
    ll s = max(0ll, l-n); 
    ll c = min({l,(m-s),n}); 
    fr (j,0,c) 
    {
    	cout << a[min(n,l)-j-1][s+j] << " " ;
    }
    cout << endl; 
}