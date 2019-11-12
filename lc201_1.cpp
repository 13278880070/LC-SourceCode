class Solution {	// return m -> n 所有数的按位与.
public:
    int rangeBitwiseAnd(int m, int n) {
    	if(m == 0) return 0;
    	if(m == n) return n;
        int len1 = (int)log2(m) + 1;
        int len2 = (int)log2(n) + 1;
        if(len1 < len2) return 0;

        int sum = 0;
        for(int i = len2; i != 0; i--) {
        	int x = pow(2, i-1);
        	sum = sum << 1;
        	int a = m / x;
        	int b = n / x;
        	if((a == b) && (a % 2)) {
        		sum |= 1;
        	}
        }

        return sum;
    }
};