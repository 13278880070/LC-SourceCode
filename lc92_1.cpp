/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// ac, 67.53%
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(m == n || head == NULL || head->next == NULL) return head;
        int i;
        ListNode node1 = ListNode(-1);
        ListNode node2 = ListNode(-1);
        ListNode* head2 = &node2, *ret = &node1, *row;
        ret->next = head;
        head = ret;

        for(i = 0; i < m-1; i++) head = head->next;
        for(i = 0; i < n-m+1; i++) {
        	row = head->next;
        	head->next = head->next->next;
        	row->next = head2->next;
        	head2->next = row;
        }
       	row = head2->next;
       	while (row->next != NULL) row = row->next;
       	row->next = head->next;
       	head->next = head2->next;
        return ret->next;
    }
};