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
class Solution {    // 每一层, 从左至右依次链接起来.
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node *pre = root, *gonext = root;

        while (pre->left != NULL) { // pre 用于进入下一层.
            gonext = pre;
            while (gonext != NULL) {    // gonext 用于处理.下一层.元素的 next
                gonext->left->next = gonext->right;
                if (gonext->next != NULL) {
                    gonext->right->next = gonext->next->left;
                }
                gonext = gonext->next;
            }
            pre = pre->left;
        }
        return root;
    }
};