class Solution {	// 一组整数, 输出组成整数最大的数.
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &n1, const int &n2) {
        	if(!n1) return 0;
			if(!n2) return 1;
        	// n1n2, n2n1 比较.
        	int len1 = (int)log10(n1) + 1;
        	int len2 = (int)log10(n2) + 1;

        	long int num1 = n1*pow(10, len2) + n2;
        	long int num2 = n2*pow(10, len1) + n1;

        	return num1 > num2 ? 1 : 0;
        });
        // 给定两个数 n1, n2.
        // 比较 "n1n2" 形成的数 和 "n2n1" 形成的数的大小.

        if(nums[0] == 0) return "0";
        string retstr;
        for(int ele : nums) retstr += to_string(ele);
        return retstr;
    }
};