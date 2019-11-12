/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorder;
    vector<int> postorder;
    unordered_map<int, int> rmap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        int i = 0;
        for(int ele : inorder) {	// 用于后面查找根节点时, 实现 O(1) 查找.
            rmap[ele] = i;
            i++;
        }
        int len = postorder.size();
        return getTree(0, len-1, len-1);
    }
    
    TreeNode* getTree(int l, int r, int rx) {
        if(l > r) return NULL;
        TreeNode* ret = new TreeNode(postorder[rx]);
        if(l == r) return ret;
        int rindex = rmap[postorder[rx]];
        ret->left = getTree(l, rindex-1, rx - (r-rindex+1));
        ret->right = getTree(rindex+1, r, rx-1);
        return ret;
    }
};