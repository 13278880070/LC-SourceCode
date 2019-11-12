class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return false;
        int l = 0, r = len - 1, mid;
        while (l <= r) {
        	mid = (r + l) >> 1;
        	if(nums[mid] == target) return true;
        	// while 处理特殊情况
        	while (nums[l] == nums[r] && nums[l] == nums[mid]) {
        		l++;
        		r--;
        		if(l > r) return false;
        	}
        	if(nums[l] <= nums[mid]) {
        		if(nums[l] <= target && target <= nums[mid]) r = mid - 1;
        		else l = mid + 1;
        	} else {
        		if(nums[mid] <= target && target <= nums[r]) l = mid + 1;
        		else r = mid - 1;
        	}
        }
        return false;
    }
};

// 特殊情况  1,1,1,1,3,1        1,2,1,1,1,1         1,1,2,1,1		....
// while 处理