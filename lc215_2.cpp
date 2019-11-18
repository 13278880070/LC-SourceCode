class Solution {	// 最大堆.
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int ele : nums) {
        	q.push(ele);
        	if(q.size() > k) q.pop();
        }
        return q.top();
    }
};