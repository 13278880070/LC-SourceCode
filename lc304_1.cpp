class NumMatrix {	// 多次调用 sumRegion 函数
private:
    vector<vector<int>> vec;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
       	int m = 0, sum;
       	int i, j, a, b;
       	if(n) m = matrix[0].size();
       	for(i = 0; i < n; i++) {
       		vector<int> v;
       		for(j = 0; j < m; j++) {
       			sum = 0;
       			a = i - 1;
       			b = j - 1;
       			if (a >= 0) sum += vec[a][j];
       			if (b >= 0) sum += v[b];

       			if (a >= 0 && b >= 0) sum -= vec[a][b];

       			v.push_back(sum + matrix[i][j]);
       		}
       		vec.push_back(v);
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