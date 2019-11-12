class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {	// 返回所有子集
        int len = nums.size();
        vector<vector<int>> retvec;
        vector<int> vec;
        createset(retvec, vec, nums, 0);
        return retvec;
    }

    void createset(vector<vector<int>>& retvec, vector<int>& vec, vector<int>& nums, int i) {
    	if(i == nums.size()) {
    		retvec.push_back(vec);
    		return ;
    	}
    	createset(retvec, vec, nums, i+1);
    	vec.push_back(nums[i]);
    	createset(retvec, vec, nums, i+1);
        vec.pop_back();
    }
};