class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {		// 使用一个 used[] 向量来记录是否被使用
        int len = nums.size();
        vector<bool> used(len, false);
        vector<vector<int>> retvec;
        vector<int> advec;
        getpermute(nums, advec, used, retvec, 0);
        return retvec;
    }

    void getpermute(vector<int>& nums, vector<int>& advec, vector<bool>& used, vector<vector<int>>& retvec, int sum) {
    	if(sum == nums.size()) {
    		retvec.push_back(advec);
    		return ;
    	}
    	for(int i = 0; i < nums.size(); i++) {
    		if(used[i] == false) {
    			used[i] = true;
    			advec.push_back(nums[i]);
    			getpermute(nums, advec, used, retvec, sum+1);
    			used[i] = false;
    			advec.pop_back();
    		}
    	}
    }
};