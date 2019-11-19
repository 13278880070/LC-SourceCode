class Solution {	// return the summary of range...
public:				// nums: 已排序
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> retvec;
        if(len == 0) return retvec;
        string str = to_string(nums[0]);

        int start = 0;
        long num;
        for(int i = 1; i < len; i++) {
        	while (i < len ) {
                num = (long)nums[i] - (long)nums[start];
                if (num != (i - start)) break;
                i++;
            }
        	if(i-1 != start) {
        		str += "->" + to_string(nums[i-1]);
        	}
            start = i;
        	retvec.push_back(str);
        	if(i == len) return retvec;
        	str = to_string(nums[i]);
        }
        retvec.push_back(str);
        return retvec;
    }
};