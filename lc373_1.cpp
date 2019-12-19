class Solution {	// 返回最小的前 k 对.
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> retvec;
        int len1 = nums1.size(), len2 = nums2.size();
        if (!len1 || !len2) return retvec;

        vector<int> index(len1, 0);
        int minindex, count = 0, minnum = INT_MAX;
        while (count < k) {
        	minnum = INT_MAX;
        	for (int i = 0; i < len1; i++) {
        		if (index[i] != len2 && nums1[i] + nums2[index[i]] < minnum) {
        			minnum = nums1[i] + nums2[index[i]];
        			minindex = i;
        		}
        		if (!index[i]) break;	// 第二个数下标为 0, 后面无需考虑了。
        	}
        	if (minnum == INT_MAX) break;	// 所有可能结果都已经遍历完了。
        	retvec.push_back(vector<int>{nums1[minindex], nums2[index[minindex]]});
            count++;
        	index[minindex]++;
        }

        return retvec;
    }
};