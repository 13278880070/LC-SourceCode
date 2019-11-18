class Solution {	// k 个 1~9 的数之和为 n
public:				// 回溯.
	vector<vector<int>> retvec;
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<int> vec;
        getCombination(vec, k, n, 1);
        return retvec;
    }

    void getCombination(vector<int> vec, int k, int leave, int start) {
    	if(k == 0) {
    		if(leave == 0) retvec.push_back(vec);
    	}
    	if(leave < 0) return;
    	for(int i = start; i <= 9; i++) {
    		vec.push_back(i);
    		getCombination(vec, k-1, leave-i, i+1);
    		vec.pop_back();
    	}
    }
};