/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {		// 将非递归中序遍历应用到该题中.
private:
	stack<TreeNode*> stk;
	TreeNode* root;
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
    }
    
    /** @return the next smallest number */
    int next() {
        while(root) {
        	stk.push(root);
        	root = root->left;
        }
        root = stk.top();
        stk.pop();
        int ret = root->val;
        root = root->right;
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return root || !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */