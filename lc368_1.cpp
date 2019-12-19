class Solution {	// 可以整除的最长整数序列.
public:				// dp...
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        vector<int> retvec;
        if (len <= 1) return nums;

        vector<int> dp(len, 1);
        vector<int> parent(len, -1);		// for output
        sort(nums.begin(), nums.end());		// sort.

        int maxcount = 0, lastindex;
        for (int i = 1; i < len; i++) {
        	for (int j = i-1; j >= 0; j--) {
        		if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
        			dp[i] = dp[j] + 1;
        			parent[i] = j;
        		}
        	}

        	if (dp[i] > maxcount) {
        		lastindex = i;
        		maxcount = dp[i];
        	}
        }

        while (parent[lastindex] != -1) {
        	retvec.push_back(nums[lastindex]);
        	lastindex = parent[lastindex];
        }
        retvec.push_back(nums[lastindex]);

        reverse(retvec.begin(), retvec.end());
        return retvec;
    }
};