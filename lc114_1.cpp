/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
    	flattenit(root);
    }

    // 每次处理, 返回当前处理结点的右子树的最右结点.
    TreeNode* flattenit(TreeNode* root) {
    	if(root == NULL) return NULL;
    	if(root->left == NULL && root->right == NULL) return root;
    	TreeNode* r_ret = flattenit(root->right);
    	TreeNode* l_ret = flattenit(root->left);
    	if(root->left == NULL) return r_ret;

    	TreeNode* r_child = root->right;
    	root->right = root->left;
    	root->left = NULL;

    	l_ret->right = r_child;
    	return r_ret == NULL ? l_ret:r_ret;
    }
};