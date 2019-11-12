/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// 对链表进行插入排序. 第二个循环从前往后遍历.
public:
    ListNode* insertionSortList(ListNode* head) {
    	if(!head || !head->next) return head;
        ListNode *ret = new ListNode(INT_MIN);
        ret->next = head;

        ListNode *tail = head, *node;

        while (tail->next) {
        	head = ret;
        	node = tail->next;
        	if(node->val >= tail->val) {
        		tail = tail->next;
        	} else {
        		tail->next = tail->next->next;
        		while (node->val > head->next->val) head = head->next;
        		node->next = head->next;
        		head->next = node;
        	}
        }
        return ret->next;
    }
};