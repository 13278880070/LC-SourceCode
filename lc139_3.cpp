class Solution {	// 94.63%.
public:				// dp. 动态规划.
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxlen = 0;
        for(string str : wordDict) {
        	maxlen = max(maxlen, (int)str.size());
        }
        // string 类型变量, size()/length() 返回的是无符号数.

        int len = s.size();
        vector<bool> dp(len+1, false);
        dp[0] = true;

        for(int i = 1; i <=len; i++) {
        	int limit = max(i-maxlen, 0);
        	for(int j = i-1; j >= limit; j--) {
        		// 长度限制. 最大长度应为 wordDict 中的最长字符串长度.
        		if(dp[j]) {
        			if(count(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != 0)
        				dp[i] = true;
        		}
        	}
        }
        return dp[len];
    }
};