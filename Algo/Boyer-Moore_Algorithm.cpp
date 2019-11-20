#include <iostream>
#include <vector>

using namespace std;


// 找到一个无序数组中出现次数 > n/2 的数
// candidate, count
int Boyer_Moore(vector<int> nums) {
	int count = 0, candidate = 0;

	for (int ele : nums) {
		if(!count) candidate = ele;
		if(candidate == ele) count++;
		else count--;
	}

	return candidate;
}

// 题目假设: 非空数组, 且保证存在正确返回值.
// count 并不一定代表 candidate 出现的总次数.

int main()
{
	vector<int> nums = {1,3,3,2,3};
	int ret = Boyer_Moore(nums);
	cout<<ret<<endl;
}