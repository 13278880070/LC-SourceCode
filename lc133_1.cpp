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
class Solution {	// 返回一个无向连通图的 deep clone. BFS.
public:
	unordered_map<Node*, Node*> onmap;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        Node* ret = node;
        onmap[node] = new Node(node->val, {});
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {	// BFS
        	node = q.front();
        	q.pop();
        	for(Node* neighbor : node->neighbors) {
        		if(onmap.find(neighbor) == onmap.end()) {	// 如果 neighbor 没有对应的新结点.
        			onmap[neighbor] = new Node(neighbor->val, {});
        			q.push(neighbor);
        		}
        		onmap[node]->neighbors.push_back(onmap[neighbor]);	// 添加 新结点 的 neighbors
        	}
        }

        return onmap[ret];
    }
};