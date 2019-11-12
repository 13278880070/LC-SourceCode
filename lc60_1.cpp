class Solution {
public:
    string getPermutation(int n, int k) {	// 做法错误.
        string retstr, str = "";
        for(char ch = '1'; ch <= n + '0'; ch++) str += ch;
        int count = 1;
    	getstr(count, k, str, 0, retstr);
    	return retstr;
    }

    void getstr(int& count, int k, string& str, int start, string& retstr) {
    	if(count == k) {
    		if(retstr.length() == 0) retstr = str;
    		return;
    	}
    	for(int i = start; i < str.length(); i++) {
    		swap(str[start], str[i]);
    		sort(str.begin()+start, str.end()-(str.length() - i));
    		if(start == i) getstr(count, k, str, start+1, retstr);
            else {
            	getstr(count+1, k, str, start+1, retstr);
            }
    		swap(str[start], str[i]);
    		count--;
    	}
    }
};