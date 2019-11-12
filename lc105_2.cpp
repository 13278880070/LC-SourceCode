/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 使用 unordered_map, O(1) 查找根节点下标.
class Solution {	// 79.96%
public:
	vector<int> preorder;
	vector<int> inorder;
	unordered_map<int, int> rmap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	this->inorder = inorder;
    	this->preorder = preorder;

    	int i = 0, len = preorder.size();
        for(auto ele : inorder) {
        	rmap[ele] = i;
        	i++;
        }

        return getTree(0, len-1, 0);
    }

    TreeNode* getTree(int l, int r, int rx) {
    	if(l > r) return NULL;
    	if(l == r) return new TreeNode(inorder[l]);
    	int mid = rmap[preorder[rx]];		
    	// O(1) 找到根节点在 inorder 中下标.
    	TreeNode* ret = new TreeNode(preorder[rx]);
    	ret->left = getTree(l, mid-1, rx+1);
    	ret->right = getTree(mid+1, r, rx + (mid-l+1));
    	return ret;
    }
};