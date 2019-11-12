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
    ListNode* deleteDuplicates(ListNode* head) {// ac...
        if(head == NULL || head->next == NULL) return head;
        ListNode node = ListNode(0);
        ListNode *ret = &node, *pre = ret;
        ListNode *n1 = head->next, *n2 = head;
        while (n1 != NULL) {
        	if(n1->val != n2->val) {
        		pre->next = n2;
        		pre = pre->next;
        		n1 = n1->next;
        		n2 = n2->next;
        	} else {
        		while (n1 != NULL && n2->val == n1->val) n1 = n1->next;
        		if(n1 == NULL) {
        			pre->next = NULL;
        			return ret->next;
        		}
        		else {
        			n2 = n1;
        			n1 = n1->next;
        		}
        	}
        }
        pre->next = n2;
        return ret->next;
    }
};