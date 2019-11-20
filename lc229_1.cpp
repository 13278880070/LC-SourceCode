class Solution {	// 共 n 个数, 返回出现次数 > n/3 的元素.
public:				// 线性时间, O(1) 空间
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();

        // cant1, cant2
        int cant1, cant2, num1 = 0, num2 = 0;

        for (int ele : nums) {
        	if(!num1 && ele != cant2) cant1 = ele;
        	else if(!num2 && ele != cant1) cant2 = ele;

        	if(ele == cant1) num1++;
        	else if(ele == cant2) num2++;
        	else {
        		num1--;
        		num2--;
        	}
        }

        num1 = 0, num2 = 0;
        for (int ele : nums) {
        	if(ele == cant1) num1++;
        	if(ele == cant2) num2++;
        }

        vector<int> retvec;

        if(num1 > len/3) retvec.push_back(cant1);
        if(num2 > len/3) retvec.push_back(cant2);

        return retvec;
    }
};