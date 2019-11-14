class Node
{
public:
    unordered_map<char, Node*> map;
    bool isLeaf;

    Node() {
        this->isLeaf = false;
    }

    bool findchar(char ch) {
        return map.find(ch) != map.end();
    }

    void admap(char ch, Node *n) {
        map[ch] = n;
    }

    Node* getNext(char ch) {
        return map[ch];
    }

};

//  ac. 23.65%.
// https://www.youtube.com/watch?v=-urNrIAQnNo
class Trie {
private:
    Node *root;
    Node *node;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node = root;
        for(char ch : word) {
            if(!node->findchar(ch)) {
                Node *adnode = new Node();
                node->admap(ch, adnode);
            }
            node = node->getNext(ch);
        }
        node->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node = root;
        for(char ch : word) {
            if(!node->findchar(ch)) return false;
            node = node->getNext(ch);
        }
        return node->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node = root;
        for(char ch : prefix) {
            if(!node->findchar(ch)) return false;
            node = node->getNext(ch);
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