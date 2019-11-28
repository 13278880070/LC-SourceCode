class Solution {	// static vector
public:				// 94%...
    int numSquares(int n) {
    	// 静态 向量, 所有测试样例使用同一个 vec.
        static vector<int> vec = {0};

        int num, m, i;
        while (vec.size() <= n) {
        	num = INT_MAX;

        	m = vec.size();

        	for(i = 1; i*i <= m; i++) {
        		num = min(num, vec[m - i*i] + 1);
        	}

        	vec.push_back(num);
        }

        return vec[n];
    }
};