class Solution {	// 找出连续子数组之和大于 s 的最短子数组.
public:				// 66.43%  时间复杂度: O(n)
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int sum = 0, l = 0, ret = INT_MAX;
        int i = 0;
        for(; i < len; i++) {
        	sum += nums[i];
        	if(sum >= s) break;
        }
        if(sum < s) return 0;

        ret = min(ret, i-l+1);
        while (i < len) {
        	while ((sum - nums[l]) >= s) {
        		sum = sum - nums[l++];
        	}
        	ret = min(ret, i-l+1);
            i++;
            if(i < len) sum += nums[i];
        }
        return ret;
    }
};