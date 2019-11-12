/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// tail   100%
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n || head == NULL || head->next == NULL) return head;
        ListNode *ret = new ListNode(-1);
        ret->next = head;
        head = ret;
        
        int i;
        for(i = 0; i < m-1; i++) head = head->next;
        ListNode *tail = head->next, *pre;
        for(i = 0; i < n-m; i++) {
        	pre = head->next;
        	head->next = tail->next;
        	tail->next = head->next->next;
        	head->next->next = pre;
        }
        return ret->next;
    }
};