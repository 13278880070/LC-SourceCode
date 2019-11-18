class Solution {	// 环形
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        if(len == 2) return max(nums[0], nums[1]);
        int dp1[len], dp2[len];
        dp1[0] = nums[0];
        dp2[0] = 0;
        dp1[1] = dp1[0];
        dp2[1] = nums[1];

        for(int i = 2; i < len-1; i++) {
        	dp1[i] = max(dp1[i-2]+nums[i], dp1[i-1]);
        	dp2[i] = max(dp2[i-2]+nums[i], dp2[i-1]);
        }
        dp2[len-1] = max(dp2[len-3]+nums[len-1], dp2[len-2]);

        return max(dp2[len-1], dp1[len-2]);
    }
};
// 两个 dp[], 一个偷第一家, 一个不偷第一家.
