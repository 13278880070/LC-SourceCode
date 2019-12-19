class Solution {	// 最长波动序列长度
public:				// donw, up,   Time: 0 ms
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;

        int donw = 1, up = 1;
        for (int i = 1; i < len; i++) {
        	if (nums[i] > nums[i-1]) {
        		up = donw + 1;
        	} else if (nums[i] < nums[i-1]) {
        		donw = up + 1;
        	}
        }

        return max(donw, up);
    }
};