class Solution {	// Bucket.
public:				// O(n) time.
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(len == 0) return 0;

        vector<int> bucket(len+1, 0);

        for(int ele : citations) {
        	if (ele >= len) bucket[len]++;
        	else bucket[ele]++;
        }

        int count = 0;
        for(int i = len; i >= 0; i--) {
        	count += bucket[i];
        	if(count >= i) {
        		return i;
        	}
        }

        return 0;
    }
};