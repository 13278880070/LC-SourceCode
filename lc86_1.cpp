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
        ListNode node = ListNode(-1);
        ListNode *ret = &node;
        ret->next = head;

        ListNode *less = ret, *temp;
        head = ret;
        while (head->next != NULL) {
        	if(head->next->val < x) {
                if(head == less) {
                    less = less->next;
                    head = head->next;
                } else {		// head != less 时的小于情况, head 不需要移动
                    temp = head->next;
                    head->next = temp->next;

                    temp->next = less->next;
                    less->next = temp;
                    less = temp;
                }
        	}
        	else head = head->next;
        	if(head == NULL) break;
        }
        return ret->next;
    }
};