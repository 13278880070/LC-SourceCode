class Solution {	// 第二种做法, 反过来做. 从下往上走. 相比于从上往下, 更简单.
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> vec = triangle.back();
        for(int i = n-2; i >= 0; i--) {
        	for(int j = 0; j <= i; j++) {
        		vec[j] = min(vec[j], vec[j+1]) + triangle[i][j];
        	}
        }
        return vec[0];
    }
};