class Solution {	// 计算表达式的算数值.
public:				// " 3 + 5/2 -1  "
    int calculate(string s) {
        istringstream in('+' + s + '+');
        long long ret = 0, PreVal = 0, n = 0;
        char ch;
        // in >> ch, 会跳过空格 ' ' !!
        // 赋给 ch 一个有值的字符.
        while (in >> ch) {
        	if(ch == '+' || ch == '-') {
        		ret += PreVal;
        		in >> PreVal;		// 没有, 则为 0
        		PreVal *= (ch == '+')? 1 : -1;
        	} else {	// 处理乘除.
        		in >> n;
        		if(ch == '*') PreVal *= n;
        		else PreVal /= n;
        	}
        }
        return ret;
    }
};