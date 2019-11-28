/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 公共祖先结点(允许为其本身)
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        bool fp = find(root->left, p);
        bool fq = find(root->left, q);

        if(fq && fp) {
        	return lowestCommonAncestor(root->left, p, q);
        }
        if(fq || fp) return root;
        return lowestCommonAncestor(root->right, p, q);
    }

    bool find(TreeNode* root, TreeNode* node) {
        if(!root) return false;
    	if(root == node) return true;
    	if(find(root->left, node)) return true;
    	if(find(root->right, node)) return true;

    	return false;
    }
};