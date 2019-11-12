#include <iostream>
#include <algorithm>

using namespace std;

// 快速排序.
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

// 冒泡排序
void bubbleSort(vector<int>& nums) {
	int len = nums.size();
	for(int i = 0; i < len; i++) {
		for(int j = i+1; j < len; j++) {
			if(nums[j] < nums[i]) {
				swap(nums[i], nums[j]);
			}
		}
	}
}

// 归并排序 (从头到尾, 一个 temp)
void mergesort(vector<int>& nums, vector<int>& temp, int l, int r) {
    if(l >= r) return ;

    int mid = (l + r) / 2, i, j, count;
    mergesort(nums, temp, l, mid);
    mergesort(nums, temp, mid+1, r);

    // 使用一个辅助数组 temp.
    for(i = l; i <= r; i++) temp[i] = nums[i];

    i = l, j = mid + 1, count = l;
    while (i <= mid || j <= r) {
        if(i > mid) nums[count] = temp[j++];
        else if(j > r) nums[count] = temp[i++];
        else if(temp[i] < temp[j]) nums[count] = temp[i++];
        else nums[count] = temp[j++];
        count++;
    }
}

int main()
{
	vector<int> vec = {5,1,2,0};
	// bubbleSort(vec);
	// qsort(vec, 0, vec.size()-1);

	vector<int> temp(vec.size(), 0);
	mergesort(vec, temp, 0, vec.size()-1);

	for(int ele : vec) {
		cout<<ele<<" ";
	}
	return 0;
}