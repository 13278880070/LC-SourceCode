class Solution {	// 返回 retvec[i] : 除了 nums[i] 之外所有元素的乘积
public:				// 使用辅助数组 help[i], 计算 nums 从 len-1 ~ i 的乘积 (倒序)
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
       	vector<int> retvec(len, 1);
        if(!len) return retvec;

        vector<int> help(len + 1, 1);
        for(int i = len-1; i >= 0; i--) {
        	help[i] = nums[i] * help[i+1];
        }

        for(int i = 0; i < len; i++) {
        	retvec[i] *= help[i+1];
        	if(i) retvec[i] *= nums[i-1];
        	if(i) nums[i] *= nums[i-1];
        }

        return retvec;
    }
};