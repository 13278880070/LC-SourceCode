class Solution {
public:
    string getPermutation(int n, int k) {
        string str(n, '0');
        int fac = 1;
        for(int i = 1; i <= n; i++) {
        	str[i-1] += i;
        	fac *= i;
        }
        // 构造 字符串 "123...n" 和 整数值 1*2*...*n

        k--;
        int i, j;
        for(i = 0; i < n; i++) {	// 计算 str[i] 上的值.
	        fac /= (n-i);
	        j = i + k/fac; // calculate index of char to put at s[i]
	        char ch = str[j];
	        // remove ch by shifting to cover up (adjust the right part).
	        for(; j > i; j--) str[j] = str[j-1];
	        // 循环左移, 以保证其他位数相对之间的大小不变.
	        k %= fac;
	        str[i] = ch;
	    }
	    return str;
    }
};