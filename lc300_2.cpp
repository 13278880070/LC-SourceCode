class Solution {    // 性能太差, 16%.
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        
        if (!len) return 0;
        
        int ret = 0;
        
        vector<int> dp(len);
        
        for(int i = 0; i < len; i++) {
            dp[i] = 1;
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
            
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};