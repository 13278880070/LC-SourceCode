/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// 中序遍历的非递归版本
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *pre = root;
        vector<int> retvec;
        stack<TreeNode*> stk;

        while (root != NULL || !stk.empty()) {
        	// 注意循环进行的条件.
        	while (root != NULL) {
        		stk.push(root);
        		root = root->left;
        	}
        	root = stk.top();
        	stk.pop();
        	retvec.push_back(root->val);
        	root = root->right;				// 同样的方法处理右子节点, 可能为空
        }
        return retvec;
    }
    // 对于每个结点, 将所有"向左"结点加入 stack.
    // 打印"向左"的最后一个节点
    // 循环, 用同样的方法循环处理 "向左"最后一个结点的右子节点
};