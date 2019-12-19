class Solution {	// 最长波动序列.
public:				// 居然过了。。。 70%.
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size(), i = 0;
        if (len <= 1) return len;

        int ret = 1, flag;
        i++;
        while (i < len && nums[i] == nums[i-1]) i++;
        if (i == len) return ret;
        flag = nums[i]-nums[i-1];
        ret++;

        i++;
        while (i < len) {
        	if ((nums[i] - nums[i-1]) * flag < 0) {
        		flag *= -1;
        		ret++;
        	}
            i++;
        }

        return ret;
    }
};