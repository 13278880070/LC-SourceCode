class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return ;
        int l = 0, r = len - 1, i;
        for(i = l; i <= r; i++) {
            if(nums[i] == 1) continue;
            if(nums[i] == 0) {
                swap(nums[i], nums[l]);
            } else if(nums[i] == 2) {
                swap(nums[i], nums[r]);
            }
            while (l < len && nums[l] == 0) l++;
            while (r >= 0 && nums[r] == 2) r--;
            i = l - 1;
        }
    }
};