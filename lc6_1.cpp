class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int x = 0, len = s.length(), inc = 2*(numRows - 1);
        string restr;
        while (x < len) {   // 第一行
        	restr += s[x];
        	x += inc;
        }
        for(x = 1; x < numRows-1; x++) {    // 中间行
        	int i = x;
        	while (i < len) {
        		restr += s[i];
        		if(i + inc - 2*x < len) restr += s[i + inc - 2*x];
        		i += inc; 
        	}
        }
        x = numRows-1;
        while (x < len) {   // 最后一行
        	restr += s[x];
        	x += inc;
        }
        return restr;
    }
};