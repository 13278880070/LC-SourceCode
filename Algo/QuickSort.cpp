#include <iostream>
#include <algorithm>

using namespace std;

void qsort(vector<int>& nums, int l, int r) {
	if(l >= r) return ;
	int i = l, j = r;
	while (l < r) {
		while (nums[l] <= nums[i] && l < j) l++;
		while (nums[r] > nums[i] && r > i) r--;
		if(l > r) break;
		swap(nums[l], nums[r]);
	}
	swap(nums[i], nums[r]);
	qsort(nums, i, r-1);
	qsort(nums, l, j);
}

int main()
{
	vector<int> vec = {2,2};
	qsort(vec, 0, vec.size()-1);
	for(int ele : vec) {
		cout<<ele<<" ";
	}
	return 0;
}