class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0] = 0;

        // i & (i-1)  =>  将最后一个 1 置 0
        // 因此, i 中 1 的个数等于上式 + 1.
        for (int i = 1; i <= num; i++) {
        	dp[i] = dp[i & (i-1)] + 1;
        }

        return dp;
    }
};