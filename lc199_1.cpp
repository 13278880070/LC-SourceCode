/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 树从上往下在最右边看到的结点集合.
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        travel(root, 0, vec);
        return vec;
    }

    void travel(TreeNode* root, int depth, vector<int> &vec) {
    	if(root == NULL) return ;
    	if(depth == vec.size()) vec.push_back(root->val);

    	travel(root->right, depth+1, vec);
    	travel(root->left, depth+1, vec);
    }
};

// 解法: 深度遍历, 向下扩展时首先处理当前结点的右子树.
// 将当前处理深度的第一个结点添加到 vector 中.
