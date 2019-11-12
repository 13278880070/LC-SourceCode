class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0) return 0;
        int m = obstacleGrid[0].size();
        if(m == 0) return 0;

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        long int a[m];		// 这里必须为 long int.   移动方法超出 int 范围.
        for(int j = 0; j < m; j++) {
        	if(obstacleGrid[0][j] == 1) {	// 当出现障碍时, 后面也全为 0
                for(; j < m; j++) a[j] = 0;
                break;
            }
        	a[j] = 1;
        }
        for(int i = 1; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		if(obstacleGrid[i][j] == 1) {
        			a[j] = 0;
        			continue;
        		}
        		if(j != 0) a[j] += a[j-1];
        	}
        }
        
        return a[m-1];
    }
};