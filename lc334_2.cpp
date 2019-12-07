class Solution {    // 判断是否存在递增的 3 个数.
public:             // 只需要使用两个整数 a, b.
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        
        int len = nums.size();
        if (len < 3) return false;
        
        for (int ele : nums) {
            if (ele > b) return true;
            if (ele <= a) a = ele;
            else if (ele < b) b = ele;
        }
        
        return false;
    }
};