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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {	// 86.84%.
        vector<vector<int>> retvec;
        if(root == NULL) return retvec;
        queue<TreeNode*> q;
        q.push(root);

        int flag = 0, size = 0;
        while (!q.empty()) {
        	size = q.size();
        	vector<int> temp;
        	for(int i = 0; i < size; q.pop(),i++) {		// 每次处理一层.
                TreeNode *node = q.front();
        		temp.push_back(node->val);
        		if(node->left != NULL) q.push(node->left);
        		if(node->right != NULL) q.push(node->right);
        	}
        	if(flag) reverse(temp.begin(), temp.end());
        	retvec.push_back(temp);
            flag = 1 - flag;
        }
        return retvec;
    }
};