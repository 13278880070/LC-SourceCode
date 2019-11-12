class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, len = nums.size(), r = len-1, mid;
        if(len <= 1) return 0;

        while (l < r) {
        	mid = (l + r) >> 1;
        	if(nums[mid] < nums[mid+1]) l = mid+1;
        	else r = mid;
        }
        return l;
    }
};