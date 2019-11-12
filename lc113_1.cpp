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
	vector<vector<int>> retvec;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<int> vec;
        getpathSum(root, vec, 0, sum);
        return retvec;
    }

    void getpathSum(TreeNode* root, vector<int>& vec, int num, int sum) {
    	if(root == NULL) return;
    	vec.push_back(root->val);
    	if(root->left == NULL && root->right == NULL) {
    		// 到达叶子结点.
    		num += root->val;
    		if(num == sum) {
    			vector<int> temp = vec;
    			retvec.push_back(temp);
    		}
    		return ;
    	}
    	num += root->val;
    	if(root->left != NULL) getpathSum(root->left, vec, num, sum);
    	if(root->right != NULL) getpathSum(root->right, vec, num, sum);
    	vec.pop_back();
    }
};