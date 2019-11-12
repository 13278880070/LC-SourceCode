class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {	// 直接回溯
        vector<vector<int>> retvec;
        vector<int> nvec;
        sort(candidates.begin(), candidates.end());
        getcombination(candidates, target, 0, nvec, retvec);
        return retvec;
    }

    void getcombination(vector<int>& vec, int remain, int index, vector<int>& nvec, vector<vector<int>>& retvec) {
    	if(remain < 0 || index == vec.size()) return;
    	if(remain == 0) {
    		retvec.push_back(nvec);
    		return;
    	}
    	vector<int>::iterator it;
    	for(; index < vec.size(); index++) {
            if(vec[index] > remain) return;
            nvec.push_back(vec[index]);
            getcombination(vec, remain - vec[index], index, nvec, retvec);
            nvec.pop_back();
    	}
    }
};