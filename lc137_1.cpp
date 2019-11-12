class Solution {    // 找到只出现一次的数. (其他都出现三次.)
public:
    int singleNumber(vector<int>& nums) {
        // 将所有数的 32bit 中的一位加起来, %3 得到只出现一次的 bit.
        int res = 0, sum;
        for(int i = 0; i < 32; i++) {
            sum = 0;
            for(int num : nums) {
                sum += ((num >> i) & 1);
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};