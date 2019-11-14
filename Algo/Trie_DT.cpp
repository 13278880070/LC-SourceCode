#include <iostream>
#include <unordered_map>

using namespace std;

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

class Trie_DT
{
private:
	Node *root;
	Node *node;
public:
	Trie_DT() {
		root = new Node();
	}
	~Trie_DT() {}
	
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

	bool startwith(string prefix) {
		node = root;
		for(char ch : prefix) {
			if(!node->findchar(ch)) return false;
			node = node->getNext(ch);
		}
		return true;
	}

	bool search(string word) {
		node = root;
		for(char ch : word) {
			if(!node->findchar(ch)) return false;
			node = node->getNext(ch);
		}
		return node->isLeaf;
	}
};

int main()
{
	Trie_DT trie = Trie_DT();
	trie.insert("apple");
	cout<<trie.search("apple")<<endl;
	cout<<trie.search("app")<<endl;
	cout<<trie.startwith("app")<<endl;
	trie.insert("app");   
	cout<<trie.search("app")<<endl;     // returns true
}