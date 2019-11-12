/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// O(nlogn) 链表排序.
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }

    // 归并排序.		45.30%
    ListNode* mergesort(ListNode *node) {
    	if(!node || !node->next) return node;

    	// 找到中间结点. 并断开为 slow, fast 两段.
    	ListNode *slow = node, *fast = node->next;
    	while (fast && fast->next) {
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	fast = slow->next;
    	slow->next = NULL;
    	slow = node;

    	slow = mergesort(slow);
    	fast = mergesort(fast);

    	ListNode *ret = new ListNode(-1);
    	node = ret;
    	while (slow || fast) {
    		if(!slow) {
    			node->next = fast;
    			fast = fast->next;
    		} else if(!fast) {
    			node->next = slow;
    			slow = slow->next;
    		}
    		else if(slow->val < fast->val) {
    			node->next = slow;
    			slow = slow->next;
    		} else {
    			node->next = fast;
    			fast = fast->next;
    		}
    		node = node->next;
    	}
    	return ret->next;
    }
};