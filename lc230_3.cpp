/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 定义额外的结点结构
class CNode
{
public:
    int count;	// 以该结点为根节点的子树的总结点数
	CNode *left;
	CNode *right;
	int val;
    
	CNode(int val) {
		this->val = val;
		this->count = 1;	// 本身 1
	}
};

class Solution {
public:
	int ret;

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;

        CNode *croot = InitCNode(root);

        getKth(croot, k);

        return ret;
    }

    void getKth(CNode* root, int k) {
    	if(!root) return ;

    	int left = root->left ? root->left->count : 0;
    	if(left == k-1) {
    		ret = root->val;
    		return ;
    	}
    	if(left > k-1) {
    		getKth(root->left, k);
    	} else {
    		getKth(root->right, k - left - 1);
    	}
    }

    CNode* InitCNode(TreeNode* root) {
    	if(!root) return NULL;
    	CNode* ret = new CNode(root->val);

    	ret->left = InitCNode(root->left);
    	ret->right = InitCNode(root->right);

    	ret->count += ret->left == NULL ? 0 : ret->left->count;
    	ret->count += ret->right == NULL ? 0 : ret->right->count;

    	return ret;
    }
};