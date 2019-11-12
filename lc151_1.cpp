class Solution {	// 反转每个单词.
public:				// 借助了额外的大量空间, 性能一般.
    string reverseWords(string s) {	
        vector<string> vec;
        int len = s.length();
        int i;
        for(i = 0; i < len; i++) {
        	while (i < len && s[i] == ' ') i++;
        	if(i == len) break;
        	string str = "";
        	while (i < len && s[i] != ' ') {
        		str += s[i];
        		i++;
        	}
        	vec.push_back(str);
        }
        string retstr = "";
        len = vec.size();
        for(i = len-1; i >= 0; i--) {
        	if(i != (len-1)) retstr += ' ';
        	retstr += vec[i];
        }
        return retstr;
    }
};