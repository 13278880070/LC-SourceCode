class Solution {	// 找到三个最接近 target 的数, ac
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = INT_MAX/100, len = nums.size(), sum;
        for(int x = 0; x < len - 2; x++) {
        	int l = x + 1, r = len - 1;
        	while (l < r) {
        		sum = nums[l] + nums[r] + nums[x];
        		if(abs(target - sum) < abs(target - ret)) ret = sum;
        		if(target > sum) l++;
        		else if(target < sum) r--;
        		else return sum;
        	}
        }
        return ret;
    }
};