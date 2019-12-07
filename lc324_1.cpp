class Solution {	// 不会做..
public:				// 思想: 1. 找到中位数 midnum		2. 从左往右, 在奇数下标放置 > midnum 的数		
					// 3. 从右往左, 在偶数下标放置 < midnum 的数.		4. 剩余空位放置 midnum.
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();

        auto midptr = nums.begin() + (len >> 1);

        nth_element(nums.begin(), midptr, nums.end(), greater<int>());
        // ?????....

        int midnum = *midptr;

        vector<int> vec(len, midnum);

        auto lptr = vec.begin() + 1, rptr = len % 2 == 0 ? vec.end() - 2 : vec.end() - 1;

        int i = len - 1;
        while (nums[i] != midnum) {
        	*rptr = nums[i--];
        	rptr -= 2;
        }

        for (; i >= 0; i--) {
        	if (nums[i] != midnum) {
        		*lptr = nums[i];
        		lptr += 2;
        	}
        }

        // int i = 0;
        // while (nums[i] != midnum) {
        // 	*rptr = nums[i++];
        // 	rptr -= 2;
        // }

        // for(; i < len; i++) {
        // 	if (nums[i] != midnum) {
        // 		*lptr = nums[i];
        // 		lptr += 2;
        // 	}
        // }

        nums = vec;
    }
};