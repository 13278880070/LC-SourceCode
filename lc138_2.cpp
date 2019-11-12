/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {    // 遍历拷贝. 
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* curr = head;

        // 原链表中的每个结点拷贝一个结点作为其下一个结点.
        while (curr) {
            curr->next = new Node(curr->val, curr->next, NULL);
            curr = curr->next->next;
        }

        // 根据原结点的 random, 处理其复制结点 random
        curr = head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // 将每个 拷贝结点 提取出来, 作为返回链表.
        Node* ret = head->next;
        curr = ret;
        Node* temp = head;
        while (curr->next) {
            temp->next = curr->next;
            temp = temp->next;
            curr->next = temp->next;
            curr = curr->next;
        }
        temp->next = NULL;
        return ret;
    }
};