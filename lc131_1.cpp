class Solution {	// 划分字符串 s, 使得每个字串都是回文.
public:				// substr 第二个参数为 长度.!!!.
    vector<vector<string>> partition(string s) {
        vector<vector<string>> retvec;
        vector<string> vec;
        getPalindrome(s, retvec, 0, vec);
        return retvec;
    }

    void getPalindrome(string s, vector<vector<string>>& retvec, int start, vector<string> vec) {
    	if(start == s.length()) {
    		retvec.push_back(vec);
    		return ;
    	}
    	for(int r = start; r < s.length(); r++) {	// 找到下一个符合要求的切割点.
    		if(isPalindrome(s, start, r)) {
    			vec.push_back(s.substr(start, r+1-start));
    			getPalindrome(s, retvec, r+1, vec);
    			vec.pop_back();
    		}
    	}
    }

    bool isPalindrome(string s, int l, int r) {
    	while (l <= r) {
    		if(s[l] != s[r]) return false;
    		l++;
    		r--;
    	}
    	return true;
    }
};