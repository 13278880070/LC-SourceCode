/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {    //  做法一: 与 116 做法一一致, 直接层次遍历, 
                    //  从右往左添加next指针即可.
public:             // 要求使用常量级额外空间, 该方法不符合题意.
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        int i, size;
        while (!q.empty()) {
            size = q.size();
            Node* pre = NULL;
            for(i = 0; i < size; i++,q.pop()) {
                Node* node = q.front();
                if(node->right != NULL) q.push(node->right);
                if(node->left != NULL) q.push(node->left);
                node->next = pre;
                // 添加 next 指向上一个结点.
                pre = node;
            }
        }
        return root;
    }
};