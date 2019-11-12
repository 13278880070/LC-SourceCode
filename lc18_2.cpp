class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> retvec;
        if(len < 4) return retvec;

        sort(nums.begin(), nums.end());     // sort
        for(int i = 0; i < len-3; i++) {
            if(i != 0) {
                while(nums[i] == nums[i-1] && i < len-3) i++;
                if(i == len - 3) return retvec;
            }
            if(nums[i+1] + nums[i+2] + nums[i+3] > target - nums[i]) return retvec;
            // 不可能出现正确结果, 直接跳出
            if(nums[len-1] + nums[len-2] + nums[len-3] >= target - nums[i]) {
            // 满足条件才继续计算
                threeSum(retvec, nums, i+1, target - nums[i], nums[i]);
            }
        }
        return retvec;
    }
    void threeSum(vector<vector<int>>& retvec, vector<int>& nums, int x, int target, int pre) {
        int cx = x;
        for(; x < nums.size()-2; x++) {
            if(x != cx) while(nums[x] == nums[x-1] && x < nums.size()-2) x++;
            int l = x + 1, r = nums.size() - 1;
            int com = target - nums[x];
            while (l < r) {
                if(nums[l] + nums[r] < com) l++;
                else if(nums[l] + nums[r] > com) r--;
                else {
                    retvec.push_back({pre, nums[x], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++; r--;
                }
            }
        }
    }
};