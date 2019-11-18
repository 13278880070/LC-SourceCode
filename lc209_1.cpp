class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int l = 0, sum = 0, ret = INT_MAX;
        int i = 0;
        while (i < len && sum < s) sum += nums[i++];
        if(i == len && sum < s) return 0;
        i--;
        while (i < len) {
            while (sum >= s) {
                sum -= nums[l++];
            }
            sum += nums[--l];
            ret = min(ret, i - l + 1);
            i++;
            if(i < len) sum += nums[i];
        }
        return ret == INT_MAX ? 0 : ret;
    }
};