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
    int countNodes(TreeNode* root) {
    	if(!root) return 0;
        TreeNode* left = root, *right = root;
        int depth = 0;
        while (right) {
        	left = left->left;
        	right = right->right;
        	depth++;
        }
        if(!left && !right) return (1<<depth - 1);
        // 如果左右均为 NULL, 说明左右高度相等, 直接 计算返回结点数
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};