class Solution {
public:
    string multiply(string num1, string num2) {
        string retstr;
        int len1 = num1.length(), len2 = num2.length();
        if((len1 == 0 && num1[0] == '0') || (len2 == 0 && num2[0] == '0')) return "0";
        int i, x, x1, x2;
        int c = 0, sum;
        char ch;
        for(x = 0; x < len1 + len2 - 1; x++) {
        	sum = c;
        	for(i = 0; i <= x; i++) {
        		x1 = len1 - 1 - i, x2 = len2 - 1 - (x - i);
        		if(x1 >= 0 && x1 < len1 && x2 >= 0 && x2 < len2) sum += (num1[x1] - '0') * (num2[x2] - '0');
        	}
        	c = sum / 10;
        	sum %= 10;
            ch = '0' + sum;
            retstr += ch;
        }
        if(c != 0) {
            ch = '0' + c;
            retstr += ch;
        }
        return retstr;
    }
};