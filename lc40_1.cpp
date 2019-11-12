class Solution {	// beat 18.31%
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> retvec;
        set<vector<int>> s;
        vector<int> nvec;
        sort(candidates.begin(), candidates.end());
        getcombination(candidates, 0, target, s, nvec);
        set<vector<int>>::iterator it;
        for(it = s.begin(); it != s.end(); it++) retvec.push_back(*it);
        return retvec;
    }

    void getcombination(vector<int>& vec, int index, int remain, set<vector<int>>& s, vector<int>& nvec) {
    	if(remain == 0) {
    		s.insert(nvec);
    		return ;
    	}
    	if(remain < 0 || index == vec.size()) return;
    	getcombination(vec, index+1, remain, s, nvec);
    	nvec.push_back(vec[index]);
    	getcombination(vec, index+1, remain - vec[index], s, nvec);
    	nvec.pop_back();
    }
};