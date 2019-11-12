class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {	// swap(nums[i], nums[j])...
        vector<vector<int>> retvec;
        getpermute(nums, retvec, 0);
        return retvec;
    }

    void getpermute(vector<int>& nums, vector<vector<int>>& retvec, int start) {
    	if(start == nums.size() - 1) {
    		retvec.push_back(nums);
    		return;
    	}
    	for(int i = start; i < nums.size(); i++) {	// 每次树向下扩展时, 考虑接下来的第一个元素
    		swap(nums[start], nums[i]);
    		getpermute(nums, retvec, start);
    		swap(nums[start], nums[i]);
    	}
    }
};