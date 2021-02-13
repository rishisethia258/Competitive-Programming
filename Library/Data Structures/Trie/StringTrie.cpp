/* ===============================================
					STRING TRIE
   =============================================== */

// This works only for lowercase letter strings
// To search a string in an array of strings

class Trie {
	private :
		class Node {
			char data;
			bool isTerminal;
			Node* Children[26];

			Node(char data, bool isTerminal) {
				this -> data = data;
				this -> isTerminal = isTerminal;
			}
			friend class Trie;
		};

		Node* root;
		ll numwords;

		void addWord(Node* Parent, string word, ll key) {
			if(key == (ll)word.size()) {
				if(! Parent -> isTerminal) {
					Parent -> isTerminal = true;
				}
				this -> numwords ++;
				return;
			}

			char ch = word[key];
			Node* child = Parent -> Children[ch - 'a'];
			if(child == NULL) {
				child = new Node(ch, false);
				Parent -> Children[ch - 'a'] = child;
			}
			this -> addWord(child, word, key + 1);
		}

		bool searchWord(Node* Parent, string word, ll key) {
			if(key == (ll)word.size()) {
				return Parent -> isTerminal;
			}

			char ch = word[key];
			Node* child = Parent -> Children[ch - 'a'];
			if(child == NULL) {
				return false;
			} 
			return searchWord(child, word, key + 1);
		}

		void removeWord(Node* Parent, string word, ll key) {
			if(key == (ll)word.size()) {
				if(Parent -> isTerminal == true) {
					Parent -> isTerminal = false;
					this -> numwords --;
				}
				return;
			}
			char ch = word[key];
			Node* child = Parent -> Children[ch - 'a'];
			if(child == NULL) {
				return;
			} else {
				removeWord(child, word, key + 1);
			}

			if(child -> isTerminal == false) {
				bool c = true;
				fr(i,0,26) {
					if(child -> Children[i] != NULL) {
						c = false;
						break;
					}
				}
				if(c) Parent -> Children[ch - 'a'] = NULL;
			}
		}

		void displayWords(Node* node, string asf) {
			if(node -> isTerminal) {
				cout << asf << endl;
			}
			fr(i,0,26) {
				if(node -> Children[i] != NULL) {
					displayWords(node -> Children[i], asf + (char)(i + 'a'));
				}
			}
		}

		void displayTrie(Node* node) {
			string ans = "";
			if(node -> data == '\0') ans += " ";
			else ans += node -> data;
			ans += " -> ";
			fr(i,0,26) {
				if(node -> Children[i] != NULL) {

					ans += node -> Children[i] -> data;
					ans += ", ";
				}
			}
			ans += ".";
			cout << ans << endl;
			fr(i,0,26) {
				if(node -> Children[i] != NULL) {
					displayTrie(node -> Children[i]);
				}
			}
		}

	public :
		Trie() {
			this -> root = new Node('\0',false);
			this -> numwords = 0;
		}
		void addWord(string word) {
			this -> addWord(this -> root, word, 0);
		}
		bool searchWord(string word) {
			return this -> searchWord(this -> root, word, 0);
		}
		void removeWord(string word) {
			removeWord(this -> root, word, 0);
		}
		void displayWords() {
			cout << "==================" << endl;
			displayWords(this -> root, "");
			cout << "==================" << endl;
		}
		void displayTrie() {
			cout << "==================" << endl;
			displayTrie(this -> root);
			cout << "==================" << endl;
		}
};

// EXAMPLE IMPLEMENTATION
// void solve() {
// 	Trie* t = new Trie();
// 	t -> addWord("ape");
// 	t -> addWord("appy");
// 	t -> addWord("apple");
// 	t -> addWord("apiapi");
// 	t -> removeWord("apiapi");
// 	t -> removeWord("appl");
// 	t -> displayWords();
// 	t -> displayTrie();
// 	bool b1 = t -> searchWord("appy"); // TRUE
// 	bool b2 = t -> searchWord("appl"); // FALSE
// }
