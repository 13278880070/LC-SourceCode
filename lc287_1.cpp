class Solution {	// 出一个数外, 其他数均只出现 1 次.
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        while (1) {
        	slow = nums[slow];
        	fast = nums[nums[fast]];

        	while (slow != fast) {
        		slow = nums[slow];
        		fast = nums[nums[fast]];
        	}

        	slow = 0;
        	while (slow != fast) {
        		slow = nums[slow];
        		fast = nums[fast];
        	}

        	return nums[slow];
        }
    }
};