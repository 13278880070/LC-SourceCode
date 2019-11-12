class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> retvec;
        int len = nums.size();
        if(len == 0) return retvec;
        vector<int> vec;
        sort(nums.begin(), nums.end());
        createset(retvec, nums, vec, 0, 1);
        return retvec;
    }

    // 对于 1,2,2,2 => 将其视为 1,  2,  (2,2),  (2,2,2) 四个元素
    // 对于 由 2 组成的元素, 如果前面已经选了一个, 则不可再选.
    // count 用于记录当前递归层"该有"的 重复元素(如 2)个数. count 为零表示前面已经加入一个由 2 组成的元素, 不能再添加.

    void createset(vector<vector<int>>& retvec, vector<int>& nums, vector<int>& vec, int index, int count) {
    	if(index == nums.size()) {
    		retvec.push_back(vec);
    		return ;
    	}
    	if(index > 0 && nums[index] == nums[index-1]) {		// 其前面出现相同, 将该数视为 count 个 nums[index].
    		if(count == 0)	createset(retvec, nums, vec, index+1, 0);
    		else {
    			createset(retvec, nums, vec, index+1, count+1);
    			for(int i = 0; i < count; i++) vec.push_back(nums[index]);
    			createset(retvec, nums, vec, index+1, 0);
    			for(int i = 0; i < count; i++) vec.pop_back();
    		}

    	} else {		// 出现"某种数"的第一个数
    		createset(retvec, nums, vec, index+1, 2);
    		vec.push_back(nums[index]);
    		createset(retvec, nums, vec, index+1, 0);
    		vec.pop_back();
    	}
    }
};