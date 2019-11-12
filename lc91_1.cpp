class Solution {		// time limit exceeded.
public:
	int ret;

    int numDecodings(string s) {
        int len = s.length();
        ret = 0;
        getnum(s, 0, len);
        return ret;
    }

    void getnum(string s, int index, int len) {
    	if(index == len) {
    		ret++;
    		return;
    	}
        if(index == len-1) {
            if(s[index] == '0') return;
            ret++;
            return;
        }
    	if(s[index] >= '1' && s[index] <= '9') getnum(s, index+1, len);
    	if((s[index] == '1') || (s[index] == '2' && s[index+1] <= '6')) {
    		getnum(s, index+2, len);
    	}
    }
};