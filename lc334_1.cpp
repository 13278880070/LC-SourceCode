class Solution {	// Increasing Triplet Subsequence.
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> vec;

        for (int ele : nums) {
        	if (vec.empty()) vec.push_back(ele);
        	else {
        		int len = vec.size();
        		if (len == 3) return true;

        		if (ele > vec[len-1]) vec.push_back(ele);
        		else {
        			for (int i = 0; i < vec.size(); i++) {
	        			if (ele == vec[i]) break;
                        if (ele < vec[i]) {
                            vec[i] = ele;
                            break;
                        }
	        		}
        		}
        	}
        }

        return vec.size() == 3;
    }
};