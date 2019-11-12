class Solution {	// ac...
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
	        		//vector<int> vec;
	        		//vec.push_back(nums[l]);
	        		//vec.push_back(nums[r]);
	        		//vec.push_back(nums[x]);
	        		//retvec.push_back(vec);
	        		retvec.push_back({nums[l], nums[r], nums[x]});
	        		l++;
	        		while (l < r && nums[l] == nums[l-1]) l++;
	        		r--;
	        		while (l < r && nums[r] == nums[r+1]) r--;
	        	}
        	}
        }
        return retvec;
    }
};