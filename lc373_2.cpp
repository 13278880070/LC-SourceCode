class Solution {	// O(n) space && O(K logN) time.
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> retvec;
        if (nums1.empty() || nums2.empty()) return retvec;

        // 定义优先级, 使用最小堆
        auto compare = [&nums1, &nums2](vector<int> a, vector<int> b) {
        	return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> min_heap(compare);

        // 使用 emplace 不产生临时变量.
        min_heap.emplace(vector<int>{0, 0});
        while (!min_heap.empty() && k) {
        	vector<int> v = min_heap.top();
        	retvec.emplace_back(vector<int>{nums1[v[0]], nums2[v[1]]});
        	min_heap.pop();

        	if (v[0] < nums1.size() - 1) {
        		min_heap.emplace(vector<int>{v[0]+1, v[1]});
        	}
        	if (!v[0] && v[1] < nums2.size()-1) {
        		min_heap.emplace(vector<int>{v[0], v[1]+1});
        	}
            k--;
        }

        return retvec;
    }
};