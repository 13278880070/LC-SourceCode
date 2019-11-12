#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Compare
{
	bool operator()(const TreeNode* n1, const TreeNode* n2) {
		return n1->val < n2->val;	// 优先级按照 val 从大到小!!
		// return n1->val > n2->val;	// 优先级按照 val 从小到大!!
	}
};

int main()
{
	vector<TreeNode*> vec;
	priority_queue<TreeNode*, vector<TreeNode*>, Compare> q;
}