class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || (s.length() == 1)) return s;
        int start = 0, len = s.length(), max_len = 0;
        for(int i = 0; i < len; ) {
        	int k = i, j = i;
        	while (k < len-1 && s[k] == s[k+1]) k++;	// 跳过相邻的相同字符
        	j = i - 1;
        	k++;
        	i = k;	// 下一个 i 从 k 往后开始判断
        	while (j >= 0 && k < len && s[j] == s[k]) {		// expand
        		j--;
        		k++;
        	}
        	if((k - j - 1) > max_len) {
        		max_len = k - j - 1;
        		start = j+1;
        	}
        }
        return s.substr(start, max_len);
    }
};