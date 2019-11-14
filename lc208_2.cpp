class Node
{
public:
    bool isLeaf;
    Node* child[26];    // 26 个字母, 使用 26 个孩子结点指针.

    Node() {
        this->isLeaf = false;
        for(int i = 0; i < 26; i++) child[i] = NULL;
    }
    
};

class Trie {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        int index;
        for(char ch : word) {
            index = ch - 'a';
            if(!node->child[index]) {
                node->child[index] = new Node();
            }
            node = node->child[index];
        }
        node->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        int index;
        for(char ch : word) {
            index = ch - 'a';
            if(!node->child[index]) return false;
            node = node->child[index];
        }
        return node->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        int index;
        for(char ch : prefix) {
            index = ch - 'a';
            if(!node->child[index]) return false;
            node = node->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */