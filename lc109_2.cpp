/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 仅使用额外的 O(1) 空间.	快慢指针.
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return getBST(head, NULL);
    }

    TreeNode* getBST(ListNode* head, ListNode* tail) {
    	if(head == tail) return NULL;
    	ListNode *slow = head, *fast = head;
    	while (fast != tail && fast->next != tail) {	// 快慢指针查找中间结点.
    		slow = slow->next;
    		fast = fast->next->next;
    	}
        TreeNode* ret = new TreeNode(slow->val);
    	ret->left = getBST(head, slow);
    	ret->right = getBST(slow->next, tail);
    	return ret;
    }
};