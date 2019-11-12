class Solution {	// 贪心法
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int mnow = 0, i = 0;
        if(size <= 1) return true;
        while (mnow < size - 1 && i < size - 1 && mnow >= i) {
        	mnow = max(mnow, i + nums[i]);
        	i++;
        }
        if(mnow < size - 1) return false;
        return true;
    }
};