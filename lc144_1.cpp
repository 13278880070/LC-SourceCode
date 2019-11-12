/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 返回一颗二叉树的前序遍历
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> retvec;
        stack<TreeNode*> stk;
        while (!stk.empty() || root) {
        	while (root) {
        		stk.push(root);
        		retvec.push_back(root->val);
        		root = root->left;
        	}
        	root = stk.front();
        	stk.pop();
        	root = root->right;
        }
        return retvec;
    }
};