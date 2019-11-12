class Solution {	// 给定一组非负整数, 返回它们能够组成的最大数.
public:
    string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
		    string str1, str2;
		    str1 = to_string(a);
		    str2 = to_string(b);

		    return (str1+str2) > (str2+str1)
		});
        string retstr;
        for(int ele : nums) {
        	retstr += to_string(ele);
        }
        return retstr[0] == '0' ? "0": retstr;
    }
};