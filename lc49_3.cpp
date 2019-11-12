class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> retvec;
        unordered_map<string, vector<string>> strmap;
        string st;
        for(int i = 0; i < size; i++) {
        	st = strs[i];
        	sort(st.begin(), st.end());
        	if(strmap.find(st) == strmap.end()) {
        		vector<string> vec;
        		vec.push_back(strs[i]);
        		strmap[st] = vec;
        	} else {
        		strmap[st].push_back(strs[i]);
        	}
        }
        unordered_map<string, vector<string>>::iterator it;
        for(it = strmap.begin(); it != strmap.end(); it++) retvec.push_back(it->second);
        return retvec;
    }
};