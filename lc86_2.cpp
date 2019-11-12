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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode node1 = ListNode(-1);
        ListNode node2 = ListNode(-1);

        ListNode *p1 = &node1, *p2 = &node2;
        while (head != NULL) {
        	if(head->val < x) {
        		p1->next = head;
        		p1 = p1->next;
        	} else {
        		p2->next = head;
        		p2 = p2->next;
        	}
        	head = head->next;
        }
        p1->next = node2.next;
        p2->next = NULL;
        return node1.next;
    }
};