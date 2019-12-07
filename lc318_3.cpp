class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        
        // 位运算存放所有 word
        vector<int> letter(len, 0);

        for(int i = 0; i < len; i++) {
        	for (char ch : words[i]) {
        		letter[i] |= 1 << (ch - 'a');
        	}
        }

        int ret = 0;
        for(int i = 0; i < len; i++) {
        	for(int j = 0; j < len; j++) {
        		if (!(letter[i] & letter[j])) {
        			ret = max(ret, (int)(words[i].length() * words[j].length()));
        		}
        	}
        }

        return ret;
    }
};