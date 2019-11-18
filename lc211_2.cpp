class Node {
public:
    Node* chlid[26];
    bool isLeaf;

    Node() {
        this->isLeaf = false;
        for(int i = 0; i < 26; i++) chlid[i] = NULL;
    }
};

// 没做出来.
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    // 非递归实现
    bool search(string word) {
        int len = word.length(), x = 0;
        stack<Node*> nodestk;
        Node* node = root;
        nodestk.push(node);
        while (x < len) {
            node = nodestk.top();
            nodestk.pop();

            if(word[x] != '.') {
                node = node->chlid[word[x]-'a'];
                if(!node) x--;
                else nodestk.push(node);
            } else {
                for(int i = 25; i >= 0; i--) {
                    if(node->chlid[i]) {
                        nodestk.push(node->chlid[i]);
                    }
                }
            }
            x++;
        }
        node = nodestk.top();
        return node->isLeaf;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */