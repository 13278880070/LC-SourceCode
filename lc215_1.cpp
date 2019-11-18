class Solution {	// 找到第 k 大的数.
public:				// My Solution: 利用快速排序过程中的下标
	int ret;
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return findKth(nums, 0, len-1, k-1);
    }

    // partition.
    int findKth(vector<int>& nums, int l, int r, int k) {
    	int x = nums[l];
    	int rl = l;
    	int rr = r;
    	while (l < r) {
    		while (l < rr && nums[l] >= x) l++;
    		while (r > rl && nums[r] < x) r--;
    		if (l > r) break;
    		swap(nums[l], nums[r]);
    	}
    	swap(nums[rl], nums[r]);
    	int ret;
    	if(r < k) {
    		ret = findKth(nums, l, rr, k);
    	} else if(r > k) {
    		ret = findKth(nums, rl, r-1, k);
    	} else ret = nums[r];
    	return ret;
    }
};