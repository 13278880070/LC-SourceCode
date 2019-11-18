class Solution {	// dp 解法
public:				// dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1.
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
       	int m;
       	if (n == 0) return 0;
        m = matrix[0].size();

       	int i, j, x;
       	int dp[n][m];
       	int ret = 0;
       	for(i = 0; i < n; i++) {
       		for(j = 0; j < m; j++) {
       			if(matrix[i][j] == '0') dp[i][j] = 0;
       			else {
       				dp[i][j] = 1;
       				if(i > 0 && j > 0) {
	       				dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
	       			}
	       			ret = max(ret, dp[i][j]);
       			}
       		}
       	}
       	return ret*ret;
    }
};