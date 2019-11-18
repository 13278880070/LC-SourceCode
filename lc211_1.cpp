class Node {
public:
	Node* chlid[26];
	bool isLeaf;

	Node() {
		this->isLeaf = false;
		for(int i = 0; i < 26; i++) this->chlid[i] = NULL;
	}
};

// 回溯 + Trie  =>  22.21%
class WordDictionary {
private:
	Node *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* node = root;
		int x;
		for (char ch : word) {
			x = ch - 'a';
			if (!node->chlid[x]) {
				node->chlid[x] = new Node();
			}
			node = node->chlid[x];
		}
		node->isLeaf = true;
    }

    bool ch2next(Node* node, string word, int x) {
    	bool re = false;
    	if(node == NULL) return false;
    	if (x == word.length()) return node->isLeaf;

    	if (word[x] == '.') {
    		for (int i = 0; i < 26; i++) {
    			if (node->chlid[i]) {
    				re = ch2next(node->chlid[i], word, x+1);
    				if (re) break;
    			}
    		}
    	} else {
    		node = node->chlid[word[x]-'a'];
    		re = ch2next(node, word, x+1);
    	}
    	return re;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return ch2next(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */