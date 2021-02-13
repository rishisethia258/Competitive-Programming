/*=====================================================
 	To find the smallest element in Queue in O(1) time
  =====================================================*/

// METHOD 1 -
// In this method we must know the value of 
// element we are removing.

// Implementation - Declaring deque globally
// Finding Minimum - findMin()
// Adding an Element - add()
// Removing an Element - remove()

deque<ll> q;

ll findMin() {
	return q.front();
}

void add(ll new_element) {
	while(!q.empty() && q.back() > new_element) {
		q.pop_back();
	}
	q.push_back(new_element);
}

void remove(ll remove_element) {
	if(!q.empty() && q.front() == remove_element) {
		q.pop_front();
	}
}

// METHOD 2 -
// In this method we must not know the value of element
// to be removed. We use two another variables

// Implementation - Declaring variables globally
// Finding Minimum - findMin()
// Adding an Element - add()
// Removing Element - remove()

deque<pair<ll,ll>> q;
ll cnt_added = 0;
ll cnt_removed = 0;

ll findMin() {
	ll minimum = q.front().first;
	return minimum;
}

void add(ll new_element) {
	while(!q.empty() && q.back().first > new_element) {
		q.pop_back();
	}
	q.push_back({new_element,cnt_added});
	cnt_added ++;
}

void remove() {
	if(!q.empty() && q.front().second == cnt_removed) {
		q.pop_front();
	}
	cnt_removed ++;
}

// METHOD 3 
// This is implementing Queue using 2 stacks

// Implementation - Declaring Stacks
// Finding Minimum - findMin()
// Adding an Element - add()
// Removing an Element - remove()

stack<pair<ll,ll>> s1,s2;

ll findMin() {
	ll m;
	if(s1.empty() || s2.empty()) {
		m = s1.empty() ? s2.top().second :s1.top().second;
	} else {
		m = min(s1.top().second, s2.top().second);
	}
	return m;
}

void add(ll new_element) {
	ll m;
	if(s1.empty()) {
		m = new_element;
	} else {
		m = min(new_element, s1.top().second);
	}
	s1.push({new_element,m});
}

void remove() {
	if(s2.empty()) {
		while(!s1.empty()) {
			ll element = s1.top().first;
			s1.pop();
			ll m;
			if(s2.empty()) {
				m = element;
			} else {
				m = min(element, s2.top().second);
			}
			s2.push({element, m});
		}
	}
	ll remove_element = s2.top().first;
	s2.pop();
}