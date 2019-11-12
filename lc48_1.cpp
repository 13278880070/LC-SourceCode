class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {	// 
        int n = matrix.size();
        for(int i = 1; i < n; i++) {
        	for(int j = 0; j < i; j++) {
        		swap(matrix[i][j], matrix[j][i]);
        	}
        }

        for(int i = 0; i < n / 2; i++) {	// 交换第 i 列和第 n - i - 1 列
        	for(int j = 0; j < n; j++) {
        		swap(matrix[j][i], matrix[j][n-1-i]);
        	}
        }
        return;
    }
};