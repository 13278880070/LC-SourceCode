class Solution {	// 返回由 '1' 构成的最大正方形
public:				// 8.36%.
    int maximalSquare(vector<vector<char>>& matrix) {
       	int n = matrix.size();
       	int m;
       	if (n) m = matrix[0].size();

       	int ret = 0;
       	vector<int> vec(m, 0);
       	int i, j, x;
       	for(i = 0; i < n; i++) {
       		for(x = 0; x < m; x++) {
       			if(matrix[i][x] == '1') vec[x]++;
       			else vec[x] = 0;
       		}
       		for(j = 0; j < m; j++) {
       			if(vec[j] > ret) {
       				for(x = vec[j]; x > ret; x--) {	// 查找是否有连续 x 个 >= x 的值
       					if(m-j < x) continue;
       					int y = 0;
       					while (y < x) {
       						if(vec[y+j] < x) break;
       						y++;
       					}
       					if (y == x) ret = x;
       				}
       			}
       		}
       	}

       	return ret*ret;
    }
};