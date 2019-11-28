class NumMatrix { // 多次调用 sumRegion 函数
private:
    vector<vector<int>> vec;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = 0, sum;
        int i, j;
        if(n) m = matrix[0].size();

        vec = vector<vector<int>>(n, vector<int>(m));

        for(i = 0; i < n; i++) {
          for(j = 0; j < m; j++) {
            sum = 0;
            if (i) sum += vec[i-1][j];
            if (j) sum += vec[i][j-1];

            if (i && j) sum -= vec[i-1][j-1];

                vec[i][j] = sum + matrix[i][j];
          }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (!vec.size()) return 0;
        int ret = vec[row2][col2];

        if (row1) ret -= vec[row1-1][col2];
        if (col1) ret -= vec[row2][col1-1];

        if (row1 && col1) ret += vec[row1-1][col1-1];

        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */