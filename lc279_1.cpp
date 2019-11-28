class Solution {	// 超时.
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 0;
        dp[1] = 1;

        int x;
        for(int i = 1; i <= n; i++) {
        	x = (int)sqrt(i);
        	if(x * x == i) dp[i] = 1;
        	else {
        		for(int j = 1; j*j < i; j++) {
	        		dp[i] = min(dp[i], dp[i-j*j] + 1);
	        	}
        	}
        }

        return dp[n];
    }
};