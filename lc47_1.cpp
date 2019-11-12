class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {	// 给定向量中有重复数
        vector<vector<int>> retvec;
        sort(nums.begin(), nums.end());
        getpermute(nums, retvec, 0);
        return retvec;
    }

    void getpermute(vector<int>& nums, vector<vector<int>>& retvec, int start) {
    	if(start == nums.size() - 1) {
    		retvec.push_back(nums);
    		return;
    	}
    	for(int i = start; i < nums.size(); i++) {
    		if(i != start && (nums[i] == nums[start] || nums[i] == nums[i-1])) continue;
    		swap(nums[start], nums[i]);
    		getpermute(nums, retvec, start+1);
    		swap(nums[start], nums[i]);
    	}
    }

    void swap(int& a, int& b) {
    	int temp = a;
    	a = b;
    	b = temp;
    }
};