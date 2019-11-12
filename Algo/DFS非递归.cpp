/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {	// DFS的非递归版本
public:             // 得到的结果同时也是二叉树的前序遍历的结果.
    vector<int> DFSTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
        	root = stk.top();
        	stk.pop();

        	vec.push_back(root->val);
        	// 非二叉树, 将当前结点的孩子结点, 从右至左依次入栈.
        	if(root->right) stk.push(root->right);
        	if(root->left) stk.push(root->left);
        }

        return vec;
    }
};