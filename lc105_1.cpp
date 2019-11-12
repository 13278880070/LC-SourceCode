/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 33.86%
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return getTree(preorder, 0, inorder, 0, len-1);
    }

    TreeNode* getTree(vector<int>& preorder, int rx, vector<int>& inorder, int l, int r) {
    	if(l > r) return NULL;
    	if(l == r) return new TreeNode(preorder[rx]);

    	TreeNode* ret = new TreeNode(preorder[rx]);
    	for(int i = l; i <= r; i++) {	// 找到父结点 rx.
    		if(inorder[i] == preorder[rx]) {
    			ret->left = getTree(preorder, rx+1, inorder, l, i-1);
    			ret->right = getTree(preorder, rx + (i-l+1), inorder, i+1, r);
    			break;
    		}
    	}
    	return ret;
    }
};