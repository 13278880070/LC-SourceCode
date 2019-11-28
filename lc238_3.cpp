class Solution {	// 一次遍历, O(1) space
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> retvec(len, 1);

        int lnum = 1, rnum = 1;

        // 用 lnum 辅助计算从前往后的乘积
        // 用 rnul 辅助计算从后往前的乘积
        for(int i = 0; i < len; i++) {
        	retvec[i] *= lnum;
        	lnum *= nums[i];

        	retvec[len-i-1] *= rnum;
        	rnum *= nums[len-i-1];
        }

        return retvec;
    }
};