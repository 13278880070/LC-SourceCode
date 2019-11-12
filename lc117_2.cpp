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
class Solution {    // 二叉树, 添加向右的 next 指针.
public:             // 直接从左往下依次处理每层即可.
    Node* connect(Node* root) {
        Node* cur = root;
        Node* pre = NULL;
        Node* head = NULL;  // 记录当前处理的该层的首元素, 作为下次跳转到下一层的开始.

        while (cur != NULL) {
            while (cur != NULL) {   // 每层.
                // 处理每个 next 连接的结点的左子节点, 右子节点.
                // 处理该层时, pre 为 NULL 说明还没有处理过该层的结点.
                if(cur->left != NULL) {
                    if(pre != NULL) {
                        pre->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    pre = cur->left;
                }
                if(cur->right != NULL) {
                    if(pre != NULL) {
                        pre->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    pre = cur->right;
                }
                cur = cur->next;
            }
            // 一层处理完毕, cur 指向下一层的开头.
            cur = head;
            head = NULL;
            pre = NULL;
        }
        return root;
    }
};