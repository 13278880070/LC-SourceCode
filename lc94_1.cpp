/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 二叉树的中序遍历
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> retvec;
        getTraversal(retvec, root);
        return retvec;
    }

    void getTraversal(vector<int>& vec, TreeNode *root) {
    	if(root == NULL) return;
    	getTraversal(vec, root->left);
    	vec.push_back(root->val);
    	getTraversal(vec, root->right);
    }
};