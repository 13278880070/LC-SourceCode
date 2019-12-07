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
	// 使用 Compare 定义队列优先级
	priority_queue<TreeNode*, vector<TreeNode*>, Compare> q;


	priority_queue<int, vector<int>, less<int>> q2;		// 最大堆
	priority_queue<int, vector<int>, greater<int>> q3;	// 最小堆

	for (int i = 0; i < 5; i++) {
		q2.push(i);
		q3.push(i);
	}
	// 输出: 4, 0
	cout<<q2.top()<<"  "<<q3.top()<<endl;
}