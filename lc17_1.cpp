class Solution {
public:
	string strs[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> retvec;
        getret(digits, 0, "", retvec);
        return retvec;
    }
    void getret(string digits, int x, string str, vector<string> &vec) {	// 用于递归
    	if(x == digits.length()) {
    		vec.push_back(str);
    		return;
    	}
    	string s = strs[digits[x] - '2'];		// 字母对应字符串
    	for(int i = 0; i < str.length(); i++) {
    		string ss = str + s[i];
    		getret(digits, x+1, ss, vec);
    	}
    }
};