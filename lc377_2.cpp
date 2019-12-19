class Solution {    // 组合数 IV
public:             // 依然超时...
    vector<int> dp;         // 记录, 避免重复计算
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<int>(target+1, 0);
        dp[0] = 1;
        return getCombination(nums, target);
    }

    int getCombination(vector<int>& nums, int target) {
        if (target < 0) return 0;
        if (dp[target] > 0) return dp[target];
        int ret = 0;
        for (int ele : nums) {
            ret += getCombination(nums, target-ele);
        }
        dp[target] = ret;
        return ret;
    }
};