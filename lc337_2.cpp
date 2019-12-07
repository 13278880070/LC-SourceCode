/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// DFS, house rob III
class Solution {
public:
    int rob(TreeNode* root) {
    	vector<int> ret = robit(root);

        return max(ret[0], ret[1]);
    }

    vector<int> robit(TreeNode* root) {
    	if (!root) return vector<int>{0, 0};
        
    	vector<int> vecleft = robit(root->left);
    	vector<int> vecright = robit(root->right);

    	vector<int> retvec(2);

    	// rob root
    	retvec[0] = root->val + vecleft[1] + vecright[1];
    	// don't rob root
    	retvec[1] = max(vecleft[0], vecleft[1]) + max(vecright[0], vecright[1]);
        
        return retvec;
    }
};