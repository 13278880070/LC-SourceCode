class Solution {	// 位运算
public:				// 如果 m, n 高位不相等, 则最终与运算结果必定为零.
    int rangeBitwiseAnd(int m, int n) {
    	int count = 0;
        while (m != n) {
        	m >>= 1;
        	n >>= 1;
        	count++;
        }
        return m << count;
    }
};