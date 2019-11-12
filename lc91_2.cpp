class Solution {
public:
    int numDecodings(string s) {	// dp
        int len = s.length();
        int num[len + 1];
        if(len == 0) return 0;
        if(s[0] == '0') return 0;
        num[1] = 1;
        num[0] = 1;
        for(int i = 2; i <= len; i++) {
            if(s[i-1] == '0') {     // ... ..
                if(s[i-2] == '0' || s[i-2] > '2') return 0;
                num[i] = num[i-2];
            }
        	else if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) {
                // ... . .          ... ..
        		num[i] = num[i-1] + num[i-2];
        	} else num[i] = num[i-1];   // ... . .
        }
        return num[len];
    }
};