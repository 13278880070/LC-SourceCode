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
	bool ret = true;
    bool isValidBST(TreeNode* root) {
        validBST(root);
        return ret;
    }


    vector<int> validBST(TreeNode* root) {
    	if(root == NULL) {
    		return {INT_MAX, INT_MIN};
    	}
    	vector<int> left = validBST(root->left);
    	vector<int> right = validBST(root->right);
        if(root->val == INT_MIN) {
            if(root->left != NULL) ret = false;
            if(root->right != NULL) {
                if(root->val >= right[0]) ret = false;
            }
        } else if(root->val == INT_MAX) {
            if(root->right != NULL) ret = false;
            if(root->left != NULL) {
                if(root->val <= left[1]) ret = false;
            }
        } else {
            if(root->val <= left[1] || root->val >= right[0]) ret = false;
    	    // root 的值小于等于 左子树最大值, 或者 root 的值 大于等于右子树最小值. ret = false;
        }
    	int vmin = min(root->val, left[0]);
    	int vmax = max(root->val, right[1]);
    	return {vmin, vmax};
    }
};