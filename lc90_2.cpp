class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}};
        int start;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i-1]) start = 0;       // 遇到 "第一个数"
            for(int end = result.size(); start < end; start++){ // "重复数"
                vector<int> clone = result[start];
                clone.push_back(nums[i]);
                result.push_back(clone);
            }
        }
        return result;
    }
};