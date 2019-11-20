class Solution {    // Boyer-Moore Algorithm
public:				// time: O(N), space: O(1)
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        
        for (int ele : nums) {
            if(count == 0) candidate = ele;
            if(ele == candidate) count++;
            else count--;
        }
        return candidate;
    }
};
// 题目假设:  数组非空, 总存在一个返回值.
// 最终 return 时的 count 并不一定是 candidate 出现的次数.