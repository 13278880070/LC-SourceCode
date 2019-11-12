/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 根节点到每个叶节点的整数的和.
public:
	int ret;
    int sumNumbers(TreeNode* root) {
        ret = 0;
        if(!root) return 0;
        getsum(root, 0);
        return ret;
    }

    void getsum(TreeNode* root, int num) {
    	num = num*10 + root->val;
    	if(!root->left && !root->right) {
    		ret += num;
    	} else {
    		if(root->left) getsum(root->left, num);
    		if(root->right) getsum(root->right, num);
    	}
    }
};