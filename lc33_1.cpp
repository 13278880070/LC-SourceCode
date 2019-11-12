class Solution {	// 在未知旋转轴的数组中 search 某个数
public:
    int search(vector<int>& nums, int target) {
    	int len = nums.size();
        if(len == 0) return -1;
    	return schit(nums, target, 0, len - 1);
    }

    int schit(vector<int>& vec, int target, int l, int r) {
    	int mid = (l + r) / 2;
    	if(vec[l] == target) return l;
    	if(vec[r] == target) return r;
    	if(l == r) return -1;
    	if(vec[l] <= vec[mid]) {
    		if(vec[l] <= target && target <= vec[mid]) return schit(vec, target, l, mid);
    		return schit(vec, target, mid+1, r);
    	}
    	if(vec[mid] <= target && target <= vec[r]) return schit(vec, target, mid, r);
    	return schit(vec, target, l, mid-1);
    }
};