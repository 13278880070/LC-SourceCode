class Solution {	// 性能极差...
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        int ret = 0;

        for(int i = 0; i < len; i++) {
        	for(int j = i + 1; j < len; j++) {
        		if(iscommon(words[i], words[j])) {
        			ret = max(ret, (int)(words[i].length() * words[j].length()));
        		}
        	}
        }

        return ret;
    }

    bool iscommon(string str1, string str2) {
    	vector<char> chs(26);

    	for(char ch : str1) {
    		chs[ch - 'a'] = '1';
    	}

    	for(char ch : str2) {
    		if(chs[ch] == '1') return false;
    	}

    	return true;
    }
};