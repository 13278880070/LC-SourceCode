class Solution {	// 从上往下, 每次走相邻的元素, 总和最小.
public:				// ac 56.16%
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> vec;
        vec.push_back(triangle[0][0]);
        for(int i = 1; i < n; i++) {	// 每行.
        	vec.push_back(vec[i-1] + triangle[i][i]);
        	for(int j = i-1; j > 0; j--) {
        		vec[j] = triangle[i][j] + min(vec[j], vec[j-1]);
        	}
        	vec[0] += triangle[i][0];
        }
        int ret = vec[0];
        for(int i = 1; i < vec.size(); i++) {
        	ret = min(ret, vec[i]);
        }
        return ret;
    }
};