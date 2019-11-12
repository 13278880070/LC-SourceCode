class Solution {		// O(log n) 找到 target 的 first & last position
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.emprt()) return {-1, -1};
        int len = nums.size(), l = 0, r = len - 1;
        int mid = (l + r) / 2;
        vector<int> retvec;
        while (l < r && nums[mid] != target) {
        	if(nums[mid] > target) r = mid - 1;
        	else l = mid + 1;
        	mid = (l + r) / 2;
        }
        if(l >= r) {
        	if(target == nums[l]) return {l, l};
        	return {-1, -1}
        }
        retvec.push_back(searchLeft(nums, l, mid, target));
        retvec.push_back(searchRight(nums, mid, r, target));
        return retvec;
    }

    int searchLeft(vector<int>& vec, int l, int r, int target) {
    	int mid;
    	while (l < r) {
    		mid = (l + r) / 2;
    		if(vec[mid] == target) r = mid;
    		else l = mid + 1;
    	}
    	return l;
    }

    int searchRight(vector<int>& vec, int l, int r, int target) {
    	int mid;
    	while (l < r) {
    		mid = (l + r + 1) / 2;
    		if(vec[mid] == target) l = mid;
    		else r = mid - 1;
    	}
    	return l;
    }
};