class Solution {    // k = 3, p = 1
public:             // mask = "11".
    int singleNumber(vector<int>& nums) {
        int x2 = 0, x1 = 0, mask;
        for(int num : nums) {
            x2 ^= x1 & num;
            x1 ^= num;
            mask = ~(x2 & x1);
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    }
};