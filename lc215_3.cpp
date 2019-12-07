class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto reptr = nums.begin() + k - 1;
        
        // greater, 指按照从大到小的顺序, 第 k 个.
        nth_element(nums.begin(), reptr, nums.end(), greater<int>());
        
        return *reptr;
    }
};