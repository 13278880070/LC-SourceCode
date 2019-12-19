class Solution {	// 组合数 IV
public:				// 超时, 太多重复计算
	int ret;
    int combinationSum4(vector<int>& nums, int target) {
        ret = 0;
        getCombination(nums, target);
        return ret;
    }

    void getCombination(vector<int>& nums, int target) {
    	if (target < 0) return ;
    	if (target == 0) ret += 1;
    	for (int ele : nums) {
    		getCombination(nums, target-ele);
    	}
    }
};