/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 不使用队列, 递归, 记录每层的层数 depth.
					// 93.36%
public:
	vector<vector<int>> retvec;

    vector<vector<int>> levelOrder(TreeNode* root) {
        getorder(root, 0);
        return retvec;
    }

    void getorder(TreeNode* root, int depth) {
    	if(root == NULL) return;
    	if(retvec.size() == depth) {
    	// 举例: depth: 0, retvec.size(): 0  => 说明 retvec 中还没有当前层元素
    		retvec.push_back(vector<int>());
    	}
    	retvec[depth].push_back(root->val);
    	getorder(root->left, depth+1);
    	getorder(root->right, depth+1);
    }
};