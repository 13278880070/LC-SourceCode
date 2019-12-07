class Solution {	// 桶排序, Bucket[i] 存放出现 频率 为 i 的数.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	int len = nums.size();
        vector<vector<int> > Bucket(len, vector<int>());

        unordered_map<int, int> map;
        for (int ele : nums) map[ele]++;

        unordered_map<int, int>::iterator it;
    	for (it = map.begin(); it != map.end(); it++) {
    		Bucket[it->second-1].push_back(it->first);
    	}

    	vector<int> retvec;
    	for (int i = len-1; i >= 0; i--) {
    		for (int ele : Bucket[i]) {
    			retvec.push_back(ele);
    		}
    		if (retvec.size() >= k) break;
    	}
        
        return retvec;
    }
};