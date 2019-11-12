/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {	// DFS.   实现无向连通图的 deep clone.
public:
	unordered_map<Node*, Node*> nmap;
    Node* cloneGraph(Node* node) {
    	if(nmap.find(node) != nmap.end()) return nmap[node];
        Node* ret = new Node(node->val, {});
        nmap[node] = ret;
        for(Node* neighbor : node->neighbors) {
        	ret->neighbors.push_back(cloneGraph(neighbor));
        }
        return ret;
    }
};