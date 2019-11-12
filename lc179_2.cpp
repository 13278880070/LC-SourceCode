class Solution {	// 重写 sort
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
        	string str1 = to_string(a);
        	string str2 = to_string(b);

        	int in1 = 0, in2 = 0;
        	int len1 = str1.length(), len2 = str2.length();
        	for(int i = 0; i < len1 + len2; i++) {
        		if(in1 == len1) {
        			str1 = to_string(b);
        			in1 = 0;
        		}
        		if(in2 == len2) {
        			str2 = to_string(a);
        			in2 = 0;
        		}
        		if(str1[in1] > str2[in2]) return 1;
        		else if(str1[in1] < str2[in2]) return 0;
        		in1++;
        		in2++;
        	}
        	return 0;
        });
        string retstr;
        for(int ele : nums) {
        	retstr += to_string(ele);
        }
        return retstr[0] == '0' ? "0": retstr;
    }
};