class Solution {	// 长度为 10 的重复序列.
public:				// 超时.
    vector<string> findRepeatedDnaSequences(string str) {
        vector<string> vec;
        int len = str.length();
        if(len <= 10) return vec;
		for(int i = 0; i < str.length()-10; i++) {
			string s = str.substr(i, 10);
			if(!count(vec.begin(), vec.end(), s) && str.find(s, i+1) != string::npos) vec.push_back(s); 
		}
		return vec;
    }
};