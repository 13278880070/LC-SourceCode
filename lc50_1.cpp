class Solution {
public:
    double myPow(double x, int n) {		// 直接 二分法
        int c = 0;
        if(n < 0) {
        	x = 1 / x;
        	if(n == INT_MIN) {	// 处理
                c = 1;
                n = INT_MAX;
            } else n = -n;
        }
        int p = 1, sum = 0;
        double ret = 1, mul = x;
        while (sum != n) {
        	if(p > (n - sum)) {
        		p = 1;
        		mul = x;
        	}
        	ret *= mul;
        	mul *= mul;
        	sum += p;
        	if(p > INT_MAX / 2) {	// 处理
                p = 1;
            } else p *= 2;
         }
        if(c) return ret*x;
        return ret;
    }
};