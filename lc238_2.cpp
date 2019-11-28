class Solution {	// 使用 O(1) space
public:				// 往前遍历一次, 往后遍历一次
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> retvec(len, 1);

        int help = 1;
        for(int i = 0; i < len; i++) {
        	if(i) {
        		retvec[i] *= help;
        		help = nums[i] * help;
        	} else help = nums[i];
        }

        help = 1;
        for(int i = len-1; i >= 0; i--) {
        	if(i != len-1) {
        		retvec[i] *= help;
        		help = nums[i] * help;
        	} else help = nums[i];
        }

        return retvec;
    }
};

// 优化, 将往前, 往后合并为一次遍历...