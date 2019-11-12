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
        // 选取一个根节点 r, 左边均小于 r->val, 作为左子树. 同理, 右边作为右子树.
        vector<TreeNode*> retvec;
        if(l > r) {
            retvec.push_back(nullptr);
        } if(l == r) {
            TreeNode* ret = new TreeNode(l);
            retvec.push_back(ret);
        } else {
            for(int i = l; i <= r; i++) {   // 选取一个根节点
                vector<TreeNode*> left = createTrees(l, i-1);
                vector<TreeNode*> right = createTrees(i+1, r);
                for(auto l : left) {
                    for(auto r : right) {
                        TreeNode* ret = new TreeNode(i);        // 每次都要 new 一个
                        ret->left = l;
                        ret->right = r;
                        retvec.push_back(ret);
                    }
                }
            }
        }
        return retvec;
    }
};