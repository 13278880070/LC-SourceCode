class Solution {	// 使用原地算法.	98.57%
public:
    string reverseWords(string s) {
    	int len = s.length();
    	if(len == 0) return s;

    	int storeindex = 0, i;
    	reverse(s.begin(), s.end());	// 首先 reverse 整个字符串
    	for(i = 0; i < len; i++) {
    		while (i < len && s[i] == ' ') i++;
    		if(i == len) break;
    		if(storeindex != 0) s[storeindex++] = ' ';
    		int j = i, storestart = storeindex;
    		while (s[j] != ' ' && j < len) s[storeindex++] = s[j++];
    		reverse(s.begin() + storestart, s.begin() + storeindex);
    		i = j;
    	}

    	return s.substr(0, storeindex);
    }
};