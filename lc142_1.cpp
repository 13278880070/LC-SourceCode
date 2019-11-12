/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// 快慢指针 跑操场.
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
        	fast = fast->next->next;
        	slow = slow->next;
        	if(fast == slow) {
        		while (head != slow) {
		        	head = head->next;
		        	slow = slow->next;
		        }
		        return head;
        	}
        }
        return NULL;
    }
};