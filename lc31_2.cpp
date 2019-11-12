class Solution {	// 返回比当前排列更大的下一个排列
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), l = len - 1, y = l;
        while (l > 0 && nums[l] <= nums[l-1]) l--;
        if(l != 0) {
        	while (nums[y] <= nums[l-1]) y--;
        	swap(nums[y], nums[l-1]);
        }
        y = len - 1;
        sort(nums.begin()+l, nums.begin()+y+1);     // sort: 左开右闭
    }
};