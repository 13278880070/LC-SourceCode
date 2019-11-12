/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        ListNode *h1 = new ListNode(-1);
        h1->next = head;
        ListNode *slow = h1, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 将后一段放到额外链表中.
        ListNode *h2 = new ListNode(-1);
        while (slow->next) {
            fast = slow->next;
            slow->next = slow->next->next;
            fast->next = h2->next;
            h2->next = fast;
        }

        // 将 h2->next 开始的链表 和 h1->next 开始的链表链接.
        slow = h1->next, fast = h2->next;
        ListNode *node1 = slow->next, *node2 = fast->next;
        while (1) {
            node1 = slow->next;
            node2 = fast->next;
            slow->next = fast;
            if(!node1) break;   // 退出条件: node1 == NULL
            slow = node1;
            fast->next = slow;
            fast = node2;
        }
    }
};