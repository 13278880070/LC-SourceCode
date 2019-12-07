class Solution {	// 0 ~ num 中 1 的个数
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        dp[0] = 0;

        int x;

        for (int i = 1; i <= num; i++) {
        	if (i & 1) {	// 奇数
        		dp[i] = dp[i-1] + 1;
        	} else {		// 偶数
        		x = ~(i-1);
        		// 取倒数第一个 0
        		
        		x = log2(x & -x);
        		dp[i] = dp[i-1] - (x-1);
        	}
        }

        return dp;
    }
};