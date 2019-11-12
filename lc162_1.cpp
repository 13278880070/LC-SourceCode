class Solution {	// 找峰值.
public:				// 直接遍历, 性能一般.
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int i = 1;
        while (i < len && nums[i] > nums[i-1]) i++;
        return i-1;
    }
};