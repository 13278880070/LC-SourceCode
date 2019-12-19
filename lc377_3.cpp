class Solution {	// 直接dp
public:				// 为什么想问题的时候总是没有想到直接利用已有的 nums 中的数来进行 dp 求解呢?
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
        	for (int ele : nums) {
        		if (i >= ele) dp[i] += dp[i-ele];
        		else break;
        	}
        }

        return dp[target];
    }
};