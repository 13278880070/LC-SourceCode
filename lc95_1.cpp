/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {		// 21.19%
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
    	return createTrees(1, n);
    }
    
    vector<TreeNode*> createTrees(int l, int r) {
        vector<TreeNode*> retvec;

        for(int i = l; i <= r; i++) {	// 选取一个根节点
        	vector<TreeNode*> left = createTrees(l, i-1);
        	vector<TreeNode*> right = createTrees(i+1, r);
        	for(int x = 0; x < left.size(); x++) {
        		for(int y = 0; y < right.size(); y++) {
                    TreeNode* ret = new TreeNode(i);
        			ret->left = left[x];
        			ret->right = right[y];
        			retvec.push_back(ret);
        		}
        	}
        }
        
        if(retvec.size() == 0) retvec.push_back(NULL);
        return retvec;
    }
};