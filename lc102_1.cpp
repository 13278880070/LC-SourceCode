/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {    // 层次遍历, 使用队列. 93.41%.
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> retvec;
        if(root == NULL) return retvec;
        queue<TreeNode*> q;
        q.push(root);
        
        int size;
        while (!q.empty()) {
            size = q.size();
            vector<int> vec;
            for(int i = 0; i < size; i++, q.pop()) {
                vec.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
            }
            retvec.push_back(vec);
        }
        return retvec;
    }
};