/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// 使其形成一个环.
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if(head == NULL || head->next == NULL) return head;
        int len = 1;
        ListNode* node1 = head;
        while (node1->next != NULL) {
        	len++;
        	node1 = node1->next;
        }
        node1->next = head;
        k %= len;
        node1 = head;
        for(int i = 0; i < len-k-1; i++) {
        	node1 = node1->next;
        }
        head = node1->next;
        node1->next = NULL;
        return head;
    }
};