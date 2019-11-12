/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// ac...
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode node = ListNode(0);
        ListNode* slow = &node;
        slow->next = head;

        for(int i = 0; i < n; i++) fast = fast.next;
        if(fast == NULL) return slow->next;
        while (fast != NULL) {
        	slow = slow->next;
        	fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};