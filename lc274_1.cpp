class Solution {	// 至少 h 篇论文分别被引用至少 h 次.
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int ret = 0, len = citations.size(), i;

        for(i = len-1; i >= 0; i--) {
        	ret = max(ret, min(len-i, citations[i]));
        }
        return ret;
    }
};