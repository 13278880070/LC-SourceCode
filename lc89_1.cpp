class Solution {
public:
    vector<int> grayCode(int n) {	// 位数n, 输出格雷码各数
        vector<int> retvec;
        if(n == 0) return {0};
        int x = 1, i;
        retvec.push_back(0);
        retvec.push_back(1);
        x++;
        while (x <= n) {
        	for(i = retvec.size()-1; i >= 0; i--) {
        		retvec.push_back((1<<(x-1)) + retvec[i]);
        	}
        	x++;
        }
        return retvec;
    }
};