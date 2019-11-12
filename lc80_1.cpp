class Solution {	// 删除重复项, 使得最多出现两次. O(1) 空间. 已排序
public:
	// 不会做, 光头怎么这么厉害...
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int ret = 0;
        for(int i = 0; i < len; i++) {
        	if(i < 2 || nums[i] > nums[ret-2])
        		nums[ret++] = nums[i];
        }
        return ret;
    }
};