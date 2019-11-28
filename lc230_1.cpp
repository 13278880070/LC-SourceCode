/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// return BST's kth samllest element
public:				// 使用栈来前序遍历:  21.19%.
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;

        int count = 0;
        stack<TreeNode*> stk;
        while (!stk.empty() || root) {
        	while (root) {
        		stk.push(root);
        		root = root.left;
        	}
        	root = stk.top();
        	stk.pop();
        	count++;
        	if(count == k) break;
        	root = root->right;
        }

        return root->val;
    }
};