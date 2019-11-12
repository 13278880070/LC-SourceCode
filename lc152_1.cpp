class Solution {	// 89.11 %
public:
    int maxProduct(vector<int>& nums) {
       	int len = nums.size();
       	if(len == 0) return 0;
       	if(len == 1) return nums[0];

       	// 使用 nmax, nmin 记录包含第 i-1, 到达第 i 个时的 最大/小值.
       	int nmax = nums[0], nmin = nums[0], ret = nmax;
       	for(int i = 1; i < len; i++) {
       		if(nums[i] == 0) {
       			nmax = 0;
       			nmin = 0;
       		} else {
       			int a = nmax*nums[i];
       			int b = nmin*nums[i];

       			nmax = max(nums[i], max(a, b));
       			nmin = min(nums[i], min(a, b));
       		}
       		ret = max(ret, nmax);
       	}
       	return ret;
    }
};