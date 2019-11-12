#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

struct cityNode{
	int id;
	int g;	// 已经花费的值
	int f;	// A* : f = g + Distance.   贪婪最佳优先: f = Distance.
	int depth;
	cityNode *parent;		// 指向当前结点父结点的指针.
	cityNode(int n1, int n2, int n3, int n4) : id(n1), g(n2), f(n3), depth(n4), parent(NULL){}
};

int main()
{
	vector<int> vec = {5, 4, 3, 2, 2};
	sort(vec.begin(), vec.end(), [](const int a, const int b) {
		return a < b;
	});

	for(int ele : vec) cout<<ele<<" ";
}