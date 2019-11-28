/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BST 经常 insert/delete, 且需要频繁地查找 kth 元素。
class Solution {	// 优化代码
private:
	unordered_map<TreeNode*, int> map;
	int ret;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;

        countNode(root);
        findNode(root, k);

        return ret;
    }

    void findNode(TreeNode* root, int k) {
    	int left = (map.find(root->left) == map.end()) ? countNode(root->left) : map[root->left];

    	if(left == k-1) {
    		ret = root->val;
    		return;
    	}

    	if(left > k-1) {
    		findNode(root->left, k);
    	}
    	else {
    		findNode(root->right, k - left - 1);
    	}
    }

    // 返回以 root 为根节点的子树的结点总数.
    int countNode(TreeNode* root) {
    	if(!root) return 0;
    	int left = countNode(root->left);
    	int right = countNode(root->right);

    	int ret = left + right + 1;
    	map[root] = ret;
    	return ret;
    }
};