class Solution {	// 超时.
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.length();
        vector<bool> used(len, false);
        vector<vector<string>> retvec;
        for(int i = 0; i < len; i++) {
        	if(used[i]) continue;
        	vector<string> vec;
        	vec.push_back(strs[i]);
        	for(int j = i + 1; j < len; j++) {
        		if(isequal(strs[i], strs[j])) vec.push_back(strs[j]);
        	}
        	retvec.push_back(vec);
        }
        return retvec;
    }

    bool isequal(string str1, string str2) {
    	int len1 = str1.length(), len2 = str2.length();
    	if(len1 != len2) return false;
    	int chars[256] = {};
    	for(int i = 0; i < len1; i++) chars[str1[i]]++;
    	for(int i = 0; i < len2; i++) {
    		if(chars[str2[i]] == 0) return false;
    		chars[str2[i]]--;
    	}
    	return true;
    }    
};