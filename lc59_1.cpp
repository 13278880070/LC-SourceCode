class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> retvec(n, vector<int>(n));
        int count = 1, i, j;
        int u_row = 0, d_row = n-1, l_col = 0, r_col = n-1;
        while (u_row <= d_row && l_col <= r_col) {
        	for(j = l_col; j <= r_col; j++) {
        		retvec[u_row][j] = count;
        		count++;
        	}
        	u_row++;
        	if(u_row > d_row) break;
        	for(i = u_row; i <= d_row; i++) {
        		retvec[i][r_col] = count;
        		count++;
        	}
        	r_col--;
        	if(r_col < l_col) break;
        	for(j = r_col; j >= l_col; j--) {
        		retvec[d_row][j] = count;
        		count++;
        	}
        	d_row--;
        	if(u_row > d_row) break;
        	for(i = d_row; i >= u_row; i--) {
        		retvec[i][l_col] = count;
        		count++;
        	}
        	l_col++;
        	if(l_col > r_col) break;
        }
        return retvec;
    }
};