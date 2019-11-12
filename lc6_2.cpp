class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int x = 0, len = s.length(), inc = 2*(numRows - 1), j;
        string restr;
        for(x = 0; x < numRows; x++) {    // 中间行
            int i = x;
            while (i < len) {
                restr += s[i];
                j = i + inc - 2*x;
                if(j < len && x != 0 && x != numRows-1) restr += s[j];
                i += inc; 
            }
        }
        return restr;
    }
};