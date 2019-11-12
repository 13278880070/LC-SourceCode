#include <iostream>
#include <vector>

using namespace std;

// 调用 change(&vec);
void change(vector<string> *vec) {
	vec->push_back("aaa");
	vec->push_back("bbb");
}

// 调用 change2(vec);
void change2(vector<string> &vec) {
	vec.pop_back();
}

// c1(a)
void c1(int a[]) {
	a[0] = 1;
}

// c2(a)
void c2(int *a) {
	a[0] = 2;
}

void prin(int **a) {
	cout<<a[0][0];
}

int main()
{
	// bool visit[10][10] = {};	// 全初始化为 false
	int a[3] = {1,2,3};
	int i = 0;
	cout<<a[i++];
	cout<<endl<<i;	
}