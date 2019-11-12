class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return true;
        int i = size - 2, x, n;
        bool reach[size] = {};
        reach[size - 1] = true;
        for(; i >= 0; i--) {
            n = nums[i];
            x = i;
            while (x < size && x <= i + n) {
                if(reach[x] == true) {
                    reach[i] = true;
                    break;
                }
                x++;
            }
        }
        return reach[0];
    }
};