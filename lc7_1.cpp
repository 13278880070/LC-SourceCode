class Solution {
public:
    int myAtoi(string str) {	// 字符串 => 整数
        int len = str.length(), i = 0;
        while (str[i] == ' ' && i < len) i++;
        int ret = 0, flag = 1;
        if(str[i] == '-') {
        	flag = -1;
        	i++;
        } else if(str[i] == '+') i++;	// '+' '-'
        if(!(str[i] >= '0' && str[i] <= '9')) return 0;		// alpha
        while(str[i] == '0') i++;		// '000'

        while (str[i] >= '0' && str[i] <= '9') {	// 开始处理正式数字
        	if(ret > INT_MAX/10) {
        		if(flag == 1) return INT_MAX;
        		return INT_MIN;
        	}
        	if(ret == INT_MAX/10) {
        		if(flag == 1 && str[i] >= '7') return INT_MAX;
        		if(str[i] >= '8') return INT_MIN;
        	}
        	ret = ret*10 + (str[i] - '0');
            i++;
        }
        return ret*flag;
    }
};