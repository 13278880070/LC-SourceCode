#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {  // 中序遍历.
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
        root = root->right;             // 同样的方法处理右子节点, 可能为空
    }
    return retvec;
}

vector<int> preorderTraversal(TreeNode* root) { // 前序遍历.
    vector<int> retvec;
    stack<TreeNode*> stk;
    
    while (root != NULL || !stk.empty()) {
        while (root != NULL) {
            retvec.push_back(root->val);
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        root = root->right;
    }
}



int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    vector<int> v = vec;
    cout<<v[1];
}