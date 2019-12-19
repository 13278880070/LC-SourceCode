class Solution {	// 返回 0 < x < 10^n 内不含重复数字的 x 的个数
public:				// 排列组合。。。
    int countNumbersWithUniqueDigits(int n) {
     	vector<int> dp(max(n+1, 3));
        dp[0] = 1;
     	dp[1] = 10;
     	dp[2] = 81 + dp[1];
     	if (n < 3) return dp[n];

     	int count = 9*9;

     	for (int i = 3; i <= n; i++) {
            count *= (9 - i + 2);
     		dp[i] = dp[i-1] + count;
     	}

     	return dp[n];
    }
};