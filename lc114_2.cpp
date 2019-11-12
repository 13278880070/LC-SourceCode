/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {    // 非递归, 从上往下依次处理.
public:
    void flatten(TreeNode* root) {
        while (root != NULL) {
            if(root->left != NULL) {
                TreeNode* pre = root->left;
                while (pre->right != NULL) {
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};