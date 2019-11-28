class Solution {	// 最长增长序列 (dp, 二分查找)
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;

        int ret = 0, size = 0, l, r, mid;

        vector<int> dp(len);

        for (int i = 0; i < len; i++) {
        	if (!size || nums[i] > dp[size-1]) dp[size++] = nums[i];
        	else if(nums[i] < dp[size-1]) {
        		// 使用二分查找找到插入的位置

        		l = 0, r = size-1;

        		while (l < r) {
        			mid = (l + r) >> 1;
        			if(dp[mid] > nums[i]) r = mid;
        			else if(dp[mid] < nums[i]) l = mid + 1;
        			else break;
        		}

        		if (l >= r) dp[r] = nums[i];
        	}
        }

        return size;
    }
};