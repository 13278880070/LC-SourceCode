class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return ;
        int m = matrix[0].size();
        bool zrow = false, zcol = false;
        int i, j;
        for(j = 0; j < m; j++) {
        	if(matrix[0][j] == 0) {
        		zrow = true;
        		break;
        	}
        }
        for(i = 0; i < n; i++) {
        	if(matrix[i][0] == 0) {
        		zcol = true;
        		break;
        	}
        }
        for(i = 1; i < n; i++) {
        	for(j = 1; j < m; j++) {
        		if(matrix[i][j] == 0) {
        			matrix[0][j] = 0;
        			matrix[i][0] = 0;
        		}
        	}
        }
        for(i = 1; i < n; i++) {
        	for(j = 1; j < m; j++) {
        		if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        	}
        }
        if(zrow) for(j = 0; j < m; j++) matrix[0][j] = 0;
        if(zcol) for(i = 0; i < n; i++) matrix[i][0] = 0;
    }
};