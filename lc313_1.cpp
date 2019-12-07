class Solution {	// 给定因数 primes, 找到第 n 位 Ugly Number.
public:				// 43%
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 1) return n;

        vector<int> dp(n);
        dp[0] = 1;

        int len = primes.size();
        vector<int> t(len, 0);		// 记录各自乘积.

        // 求第 n 位 Ugly Number.
        for(int i = 1; i < n; i++) {
        	dp[i] = INT_MAX;
        	for(int j = 0; j < len; j++) {
        		dp[i] = min(dp[i], dp[t[j]]*primes[j]);
        	}

        	for(int j = 0; j < len; j++) {
        		if (dp[i] == dp[t[j]]*primes[j]) t[j]++;
        	}
        }

        return dp[n-1];
    }
};