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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(head == NULL || head->next == NULL) return head;
        ListNode node = ListNode(0);
        ListNode *ret = &node;
        ListNode *pre = ret;

        while (head != NULL) {	// pre 指向当前判断的首位
        	if(head->next == NULL) {
        		pre->next = head;
        		return ret->next;
        	}
        	if(head->val == head->next->val) {
        		while (head->next != NULL && head->val == head->next->val) head = head->next;
        		if(head->next == NULL) {
        			pre->next = NULL;
        			return ret->next;
        		} else head = head->next;
        	} else {
        		pre->next = head;
        		pre = pre->next;
        		head = head->next;
        	}
        }
        return ret->next;
    }
};