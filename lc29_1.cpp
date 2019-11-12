class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == -1) {
        	if(dividend == INT_MIN) return INT_MAX;
        	return -dividend;
        }
        if(dividend == 0) return 0;
        long dvd = labs(dividend), dvs = labs(divisor), ret = 0;
        int flag = (dividend > 0) ^ (divisor > 0) ? -1 : 1;     // 判断最终结果的正负.
        long d2; int m;
        while (dvs <= dvd) {
        	d2 = dvs, m = 1;
        	while ((d2 << 1) <= dvd) {	// 一次减去 m 个 divisor. (m = pow(2, x))
        		d2 <<= 1;
        		m <<= 1;
        	}
        	ret += m;
        	dvd -= d2;
        }
        return flag > 0? ret:-ret;
    }
};