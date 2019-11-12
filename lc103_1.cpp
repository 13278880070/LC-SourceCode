/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// Z 字形遍历二叉树.
public:
	vector<vector<int>> retvec;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        getOder(root, 0);
        for(int i = 0; i < retvec.size(); i++) {
        	if(i%2 != 0) {
        		reverse(retvec[i].begin(), retvec[i].end());
        	}
        }
        return retvec;
    }

    void getOder(TreeNode* root, int depth) {
    	if(root == NULL) return ;
    	if(retvec.size() == depth) {
    		retvec.push_back(vector<int>(1, root->val));
    	} else retvec[depth].push_back(root->val);
    	getOder(root->left, depth+1);
    	getOder(root->right, depth+1);
    }
};