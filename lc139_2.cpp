class Solution {    // 字符串 s, 是否能被 wordDict 中的单词切割开来.
public:             // 46.49%.
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        bool canbk[len+1] = {false};
        canbk[0] = true;
        for(int i = 0; i <= len; i++) {
            if(canbk[i] == true) {
                for(int j = i+1; j <= len; j++) {
                    if(count(wordDict.begin(), wordDict.end(), s.substr(i, j-i)) != 0) {
                        canbk[j] = true;
                    }
                }
            }
        }
        return canbk[len];
    }
};