/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 返回完全二叉树的结点个数
public:
    int countNodes(TreeNode* root) {
    	if(!root) return 0;
        queue<TreeNode*> nodeq;
        nodeq.push(root);

        int depth = 0, ret = 1, size;
        // 层次遍历
        while (!nodeq.empty()) {
        	size = nodeq.size();
        	for(int i = 0; i < size; i++) {
        		root = nodeq.front();
        		nodeq.pop();
        		if(!root->left) {
        			ret = ret + 2*i;
        			return ret;
        		}
        		nodeq.push(root->left);
        		if(!root->right) {
        			ret = ret + 2*i + 1;
        			return ret;
        		}
        		nodeq.push(root->right);
        	}
        	depth++;
        	ret += pow(2, depth);
        }
        return ret;
    }
};