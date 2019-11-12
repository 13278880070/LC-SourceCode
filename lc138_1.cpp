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
class Solution {    // 返回一个带有 random 指针的深拷贝.
public:
    unordered_map<Node*, Node*> map;    // 使用 map 记录新旧结点的映射关系.
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* ret = new Node(head->val, NULL, NULL);
        map[head] = ret;
        while (head) {
            if(head->random) {
                if(map.find(head->random) == map.end()) {
                    map[head]->random = new Node(head->random->val, NULL, NULL);
                    map[head->random] = map[head]->random;
                } else map[head]->random = map[head->random];
            }
            if(head->next) {
                if(map.find(head->next) == map.end()) {
                    map[head]->next = new Node(head->next->val, NULL, NULL);
                    map[head->next] = map[head]->next;
                } else map[head]->next = map[head->next];
            }
            head = head->next;
        }
        return ret;
    }
};