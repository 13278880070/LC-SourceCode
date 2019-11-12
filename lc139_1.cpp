class Solution {	// 字符串 s, 是否能被 wordDict 中的单词切割开来.
public:				// 超时.
	bool ret;

    bool wordBreak(string s, vector<string>& wordDict) {
        ret = false;
        wordDic(s, 0, wordDict);
        return ret;
    }

    void wordDic(string s, int start, vector<string>& wordDict) {
    	if(start == s.length()) {
    		ret = true;
    	}
    	if(ret == true) return ;
    	int len;
    	for(int i = 0; i < wordDict.size(); i++) {
    		len = wordDict[i].length();
    		if(start + len <= s.length()) {
    			if(s.substr(start, len) == wordDict[i]) {
    				wordDic(s, start+len, wordDict);
    			}
    		}
    	}
    }
};