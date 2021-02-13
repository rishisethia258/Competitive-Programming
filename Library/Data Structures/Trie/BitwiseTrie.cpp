/*	==============================================
			   BITWISE TRIE - BINARY TRIE
	============================================== */

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

	public :
		Trie() {
			this -> root = new Node();
		}
		void insert(ll n) {
			insert(this -> root, n);
		}

};