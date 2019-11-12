/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 直接中序遍历, 比较结果是否从小到大增加
public:				// 98.52%
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> stk;
        while (root != NULL || !stk.empty()) {
        	while (root != NULL) {
        		stk.push(root);
        		root = root->left;
        	}
        	root = stk.top();
            vec.push_back(root->val);
            stk.pop();
        	root = root->right;
        }
        for(int i = 1; i < vec.size(); i++) {
        	if(vec[i] <= vec[i-1]) return false;
        }
        return true;
    }
};