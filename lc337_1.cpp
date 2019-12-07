/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// map + 递归

class Solution {    // 二叉树, 不能偷相连的结点.
public:
    unordered_map<TreeNode*, int> map1;
    unordered_map<TreeNode*, int> map2;
    int rob(TreeNode* root) {
        return robtree(root, false);
    }

    // 传入结点, 并且父节点是否被偷.
    int robtree(TreeNode* root, bool robed) {
        if (!root) return 0;

        if (robed) {
            if (map1.find(root) != map1.end()) return map1[root];
        } else {
            if (map2.find(root) != map2.end()) return map2[root];
        }

        int ret = robtree(root->left, false) + robtree(root->right, false);
        if (!robed) {
            ret = max(ret, root->val + robtree(root->left, true) + robtree(root->right, true));
        }

        if (robed) map1[root] = ret;
        else map2[root] = ret;

        return ret;
    }
};