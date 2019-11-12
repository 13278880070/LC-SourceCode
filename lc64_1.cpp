class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int count[m];
        count[0] = grid[0][0];
        for(int j = 1; j < m; j++) {
            count[j] = grid[0][j] + count[j-1];
        }
        for(int i = 1; i < n; i++) {
            count[0] += grid[i][0];
            for(int j = 1; j < m; j++) {
                count[j] = grid[i][j] + min(count[j-1],count[j]);
            }
        }
        return count[m-1];
    }
};