class Solution {		// 超时!
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retvec;
        int len = strs.size();
        for(int i = 0; i < len; i++) {
        	dealgroup(retvec, strs[i]);
        }
        return retvec;
    }

    void dealgroup(vector<vector<string>>& retvec, string str) {
    	for(int i = 0; i < retvec.size(); i++) {
    		if(isequal(retvec[i][0], str)) {
    			retvec[i].push_back(str);
    			return;
    		}
    	}
    	vector<string> vec;
    	vec.push_back(str);
    	retvec.push_back(vec);
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