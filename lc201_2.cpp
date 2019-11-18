class Solution {	// 位运算
public:				// m & m+1 & ... & n
    int rangeBitwiseAnd(int m, int n) {
    	int count = 0;
        while (m != n) {	// 找二进制中 m, n 共同的开头部分.
        	m >>= 1;
        	n >>= 1;
        	count++;
        }
        return m << count;
    }
};