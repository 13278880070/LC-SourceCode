class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, y;
        vector<int> retvec;
        for(int ele : nums) x ^= ele;
        
        // 取 x 的最后一位
        int lastbit = (x & -x);
        
        // lastbit 只可能由最后结果 a, b 中的一个提供
        // 因此, 以 lastbit 为依据, 将 a, b 划分到不同组, 并且同组中出现过两次的将变为零
        
        int a = 0, b = 0;
        for(int ele : nums) {
            if(ele & lastbit) a ^= ele;
            else b ^= ele;
        }
        
        return vector<int>{a, b};
    }
};