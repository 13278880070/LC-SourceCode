struct Compare
{
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		return a.second > b.second;	// 这里应该使用最小堆, 将优先级小的 pop 掉, 所以使用 > 号.
	}
};

class Solution {	// 返回出现频率前 k 个数
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int ele : nums) {
        	map[ele]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;

        unordered_map<int, int>::iterator it = map.begin();

        for (; it != map.end(); it++) {
        	q.push(pair<int, int>(it->first, it->second));
        	if (q.size() > k) q.pop();
        }

        vector<int> retvec;
        while (!q.empty()) {
        	retvec.push_back(q.top().first);
        	q.pop();
        }

        return retvec;
    }
};