class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> retvec;
        int len = nums.size();
        if(len < 3) return retvec;
        sort(nums.begin(), nums.end());		// sort
        int l, r, sum;
        for(int x = 0; x < len - 2; x++) {
            while (x > 0 && x < len - 2 && nums[x] == nums[x-1]) x++;
        	l = x + 1;
        	r = len - 1;
        	while (l < r) {
        		sum = nums[l] + nums[r] + nums[x];
	        	if(sum > 0) r--;
	        	else if(sum < 0) l++;
	        	else {
                    retvec.push_back({nums[l], nums[r], nums[x]});
	        		while (l < r && nums[l] == nums[l+1]) l++;
	        		while (l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
	        	}
        	}
        }
        return retvec;
    }
};