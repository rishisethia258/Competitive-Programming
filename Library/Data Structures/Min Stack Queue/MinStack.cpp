/*=====================================================
 	To find the smallest element in Stack in O(1) time
  =====================================================*/

// Implementation - Declaring stack globally
// Adding An Element to Stack - add()
// Removing Element of Stack - remove()
// Finding Minimum - findMin()

stack<pair<ll,ll>> st;

void add(ll new_elem) {
	ll new_min;
	if(st.empty()) {
		new_min = new_elem;
	} else {
		new_min = min(new_elem, st.top().second);
	}
	st.push({new_elem, new_min});
}

void remove() {
	ll removed Element = st.top().first;
	st.pop();
}

ll findMin() {
	ll minimum = st.top().second;
	return minimum;	
}