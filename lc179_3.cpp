class Solution {	// 重写 sort
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strvec;
        for(int ele : nums) strvec.push_back(to_string(ele));

        sort(strvec.begin(), strvec.end(), [](const string &str1, const string &str2) {
            // 单个字符进行比较.
            // in1 先从 str1 开始, 比较完成后重新从 str2 开始.
            // in2 先从 str2 开始, 比较完成后重新从 str1 开始
        	int in1 = 0, in2 = 0;
        	int len1 = str1.length(), len2 = str2.length();
            string s1 = str1, s2 = str2;
        	for(int i = 0; i < len1 + len2; i++) {
        		if(in1 == len1) {
        			s1 = str2;
        			in1 = 0;
        		}
        		if(in2 == len2) {
        			s2 = str1;
        			in2 = 0;
        		}
        		if(s1[in1] > s2[in2]) return 1;
        		else if(str1[in1] < s2[in2]) return 0;
        		in1++;
        		in2++;
        	}
        	return 0;
        });
        if(strvec[0][0] == '0') return "0";
        string retstr;
        for(string s : strvec) retstr += s;
        return retstr;
    }
};