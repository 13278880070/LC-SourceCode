class Solution {	// 最大堆.
public:				// O(N lg K)
    int findKthLargest(vector<int>& nums, int k) {
    	// 最大堆
        priority_queue<int, vector<int>, greater<int>> q;

        // 需要先添加, 后 pop!
		for (int ele : nums) {
            q.push(ele);
            if (q.size() > k) q.pop();
        	// if (q.size() == k) q.pop();  ERROR
        	// q.push(ele);
        }

        return q.top();
    }
};