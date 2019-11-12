class Solution {    // 8题..
public:
    int myAtoi(string str) {    // 字符串 => 整数
        int len = str.length(),
            i = str.find_first_not_of(' ');
        if(i < 0) return 0;
        int ret = 0, flag = 1;
        if(str[i] == '-') {
            flag = -1;
            i++;
        } else if(str[i] == '+') i++;   // '+' '-'
        
        while(str[i] == '0') i++;       // '000'

        while (isdigit(str[i])) {   // 开始处理正式数字
            if(ret > INT_MAX/10 || (ret == INT_MAX/10 && str[i] > '7')) {
                if(flag == 1) return INT_MAX;
                return INT_MIN;
            }
            ret = ret*10 + (str[i++] - '0');
        }
        return ret*flag;
    }
};