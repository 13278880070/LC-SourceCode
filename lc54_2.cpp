class Solution {	// 螺旋遍历一个二位数组
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int u_row = 0, d_row = matrix.size()-1, l_col = 0;
        vector<int> retvec;
        if(d_row < u_row) return retvec;
        int r_col = matrix[0].size() - 1;
        if(r_col < l_col) return retvec;
        int i, j;
        // 用 u_row, d_row, l_col, r_col 表示四个边界.
        // 每添加完一个边界, 相应边界的值 -1.
        // 判断边界是否依然合格, 否则退出.
        while (u_row <= d_row && l_col <= r_col) {
        	for(j = l_col; j <= r_col; j++) {
        		retvec.push_back(matrix[u_row][j]);
        	}
        	u_row++;
        	if(u_row > d_row) break;
        	for(i = u_row; i <= d_row; i++) {
        		retvec.push_back(matrix[i][r_col]);
        	}
        	r_col--;
        	if(r_col < l_col) break;
        	for(j = r_col; j >= l_col; j--) {
        		retvec.push_back(matrix[d_row][j]);
        	}
        	d_row--;
        	if(u_row > d_row) break;
        	for(i = d_row; i >= u_row; i--) {
        		retvec.push_back(matrix[i][l_col]);
        	}
        	l_col++;
        	if(r_col < l_col) break;
        }
        return retvec;
    }
};