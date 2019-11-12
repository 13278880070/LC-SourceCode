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
class Solution {	// ListNode* 按照升序排列, 按照元素个数分开即可.
public:
	vector<int> vec;
    TreeNode* sortedListToBST(ListNode* head) {
        while (head != NULL) {
        	vec.push_back(head->val);
        	head = head->next;
        }
        return getBST(0, vec.size()-1);
    }

    TreeNode* getBST(int l, int r) {
    	if(l > r) return NULL;
    	if(l == r) return new TreeNode(vec[l]);
    	int mid = (l + r) / 2;
    	TreeNode* ret = new TreeNode(vec[mid]);
    	ret->left = getBST(l, mid-1);
    	ret->right = getBST(mid+1, r);
    	return ret;
    }
};