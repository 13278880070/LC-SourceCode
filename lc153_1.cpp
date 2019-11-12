class Solution {	// 旋转数组最小值.
public:				// 二分法.	76.94%.
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid;
        while (l < r) {
        	mid = (l + r) >> 1;
        	if(nums[l] > nums[mid]) r = mid;
        	else if(nums[mid] > nums[r]) l = mid + 1;
        	else break;
        }
        return nums[l];
    }
};