#include <iostream>
#include <algorithm>

using namespace std;

void QuickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return ;
    int l = left, r = right, pivot = nums[l];
    while (l <= r) {
        if (nums[l] > pivot && nums[r] < pivot) {
            swap(nums[l++], nums[r--]);
        }
        while (l <= r && nums[l] <= pivot) {
            l++;
        }
        while (l <= r && nums[r] >= pivot) {
            r--;
        }
    }
    swap(nums[left], nums[r]);
    QuickSort(nums, left, r-1);
    QuickSort(nums, r+1, right);
}

int main()
{
	vector<int> vec = {7, 5, 0, 3, 2, 6, 9, 1, 0, 2};
	QuickSort(vec, 0, vec.size()-1);
	for(int ele : vec) {
		cout<<ele<<" ";
	}
	return 0;
}