class Solution {	// 返回比当前排列更大的下一个排列
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), l = len - 1, y = l;
        while (l > 0 && nums[l] < nums[l-1]) l--;
        if(l != 0) {
        	while (nums[y] < nums[l-1]) y--;
        	swapvec(nums, y, l-1);
        }
        y = len - 1;
        while (l < y) {
        	swapvec(nums, l, y);
        	l++;
        	y--;
        }
    }

    void swapvec(vector<int>& vec, int x, int y) {
    	int temp = vec[x];
    	vec[x] = vec[y];
    	vec[y] = temp;
    }
};